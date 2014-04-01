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

private:
    QTcpSocket *tcpSocket;
    QNetworkSession *networkSession;

    QString m_host;
    int m_port;
};

#endif // PRCONNECTION_H
