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
public:
    explicit PRConnection(QObject *parent = 0);

    QString host() const { return m_host;}
    int port() const { return m_port; }

signals:
    void hostChanged(QString arg);
    void portChanged(int arg);

public slots:
    void setHost(QString arg);
    void setPort(int arg);
    void connectToRobot();
    void readData();
    void displayError(QAbstractSocket::SocketError socketError);
    void sessionOpened();

private:
    QTcpSocket *m_tcpSocket;
    QNetworkSession *m_networkSession;

    QString m_host;
    int m_port;
    qint16 blockSize;
};

#endif // PRCONNECTION_H
