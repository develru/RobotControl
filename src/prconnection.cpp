#include <QtNetwork>

#include "prconnection.h"

PRConnection::PRConnection(QObject *parent) :
    QObject(parent),
    m_networkSession(0),
    m_host("localhost"),
    m_port(9999),
    m_sendEnable(false)
{
    m_tcpSocket = new QTcpSocket(this);

    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(m_tcpSocket,
            SIGNAL(error(QAbstractSocket::SocketError)),
            this,
            SLOT(displayError(QAbstractSocket::SocketError)));

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
                QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        m_networkSession = new QNetworkSession(config, this);
        connect(m_networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        m_networkSession->open();
    }
}

QString PRConnection::host() const
{
    return m_host;
}

int PRConnection::port() const
{
    return m_port;
}

QString PRConnection::logMsg() const
{
    return m_logMsg;
}

bool PRConnection::sendEnable() const
{
    return m_sendEnable;
}

void PRConnection::setHost(QString arg)
{
    if (m_host != arg) {
        m_host = arg;
        emit hostChanged(arg);
    }
}

void PRConnection::setPort(int arg)
{
    if (m_port != arg) {
        m_port = arg;
        emit portChanged(arg);
    }
}

void PRConnection::connectToRobot()
{
    qDebug("Try to connect");
    setLogMsg("Try to connect");

    blockSize = 0;
    m_tcpSocket->abort();
    m_tcpSocket->connectToHost(m_host, m_port);
    //    readData();
}

void PRConnection::readData()
{
    //    QDataStream in(m_tcpSocket);
    //    in.setVersion(QDataStream::Qt_4_0);

    //    if (blockSize == 0) {
    //        if (m_tcpSocket->bytesAvailable() < (int)sizeof(quint16))
    //            return;

    //        in >> blockSize;
    //    }

    //    if (m_tcpSocket->bytesAvailable() < blockSize)
    //        return;

    //    QString nextFortune;
    //    in >> nextFortune;
    //    qDebug(nextFortune.toStdString().c_str());

    char buff[1024];
    qint64 lineLength = m_tcpSocket->readLine(buff, sizeof(buff));
    if (lineLength != -1) {
        QString message = QString(buff);

        if (message == "Connected") {
            setSendEnable(true);
        }

        setLogMsg(message);
    }

}

void PRConnection::displayError(QAbstractSocket::SocketError socketError)
{
    qDebug("Error!");

    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        setLogMsg(tr("The host was not found. Please check the host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        setLogMsg(tr("The connection was refused by the peer. "
                     "Make sure the fortune server is running, "
                     "and check that the host name and port "
                     "settings are correct."));
        break;
    default:
        setLogMsg(tr("The following error occurred: %1.")
                  .arg(m_tcpSocket->errorString()));
    }
}

void PRConnection::sessionOpened()
{
    qDebug("Seession is Opened");
}

void PRConnection::setLogMsg(QString arg)
{
    m_msgList.push_front(arg + '\n');
    m_logMsg = m_msgList.join("\n");
    emit logMsgChanged(arg);
}

void PRConnection::setSendEnable(bool arg)
{
    if (m_sendEnable != arg) {
        m_sendEnable = arg;
        emit sendEnableChanged(arg);
    }
}

void PRConnection::sendMessage(QString msg)
{
    qDebug("Send");

    int count = m_tcpSocket->write(msg.toLatin1());
    m_tcpSocket->waitForBytesWritten(-1);
    setLogMsg("Message: " + msg + "(sent " + QString(count) + " byte)");
}
