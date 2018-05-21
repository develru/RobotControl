#include <QtCore/QDebug>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtCore/QSettings>
#include <QtNetwork/QNetworkSession>

#include "controller.h"

using namespace robot;

Controller::Controller(QObject *parent) :
    QObject(parent),
    tcpSocket(new QTcpSocket(this))
{
    in.setDevice(tcpSocket);

    connect(tcpSocket, &QIODevice::readyRead, this, &Controller::readMessage);
    connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
            this, &Controller::displayError);

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

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, &QNetworkSession::opened, this, &Controller::sessionOpened);

        networkSession->open();
    }
}

Controller::~Controller()
{

}

void Controller::connectToRobot(const QString ip, const QString port)
{
    qDebug() << ip << ":" << port;
    tcpSocket->abort();
    tcpSocket->connectToHost(ip, port.toInt());
}

void Controller::sendCommand(const QString cmd)
{
    qDebug("Send");

    int count = tcpSocket->write(cmd.toLatin1());
    tcpSocket->waitForBytesWritten(-1);
    qDebug() << "Message: " << cmd << "(sent " << count << " byte)";
}
void Controller::sessionOpened()
{
    // Save the used configuration
    QNetworkConfiguration config = networkSession->configuration();
    QString id;
    if (config.type() == QNetworkConfiguration::UserChoice)
        id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
    else
        id = config.identifier();

    QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
    settings.beginGroup(QLatin1String("QtNetwork"));
    settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
    settings.endGroup();

}

void Controller::displayError(QAbstractSocket::SocketError socketError)
{
    qDebug() << "Error!";
}

void Controller::readMessage()
{
    // in.startTransaction();
    // QString msg;
    // in >> msg;

    // if (!in.commitTransaction())
    //     return;

    char buff[1024];
    qint64 lineLength = tcpSocket->readLine(buff, sizeof(buff));
    if (lineLength != -1) {
        QString msg = QString(buff);

    qDebug() << msg;
    }
}
