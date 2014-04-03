#ifndef PRCONNECTION_H
#define PRCONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QString>

class QNetworkSession;

class PRConnection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString host READ host WRITE setHost NOTIFY hostChanged)
    Q_PROPERTY(int port READ port WRITE setPort NOTIFY portChanged)
    Q_PROPERTY(QString logMsg READ logMsg WRITE setErrorMsg NOTIFY errorMsgChanged)
    Q_PROPERTY(bool sendEnable READ sendEnable WRITE setSendEnable NOTIFY sendEnableChanged)
public:
    explicit PRConnection(QObject *parent = 0);

    QString host() const;
    int port() const;
    QString logMsg() const;
    bool sendEnable() const;

signals:
    void hostChanged(QString arg);
    void portChanged(int arg);
    void errorMsgChanged(QString arg);

    void sendEnableChanged(bool arg);

public slots:
    void setHost(QString arg);
    void setPort(int arg);
    void connectToRobot();
    void readData();
    void displayError(QAbstractSocket::SocketError socketError);
    void sessionOpened();
    void setErrorMsg(QString arg);
    void setSendEnable(bool arg);

private:
    QTcpSocket *m_tcpSocket;
    QNetworkSession *m_networkSession;

    QString m_host;
    int m_port;
    qint16 blockSize;
    QString m_logMsg;
    QStringList m_msgList;
    bool m_sendEnable;
};

#endif // PRCONNECTION_H
