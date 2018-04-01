#ifndef ROBOT_CONTROLLER_H
#define ROBOT_CONTROLLER_H

#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtNetwork/QTcpSocket>
#include <QtCore/QDataStream>

class QNetworkSession;

namespace robot {

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    ~Controller();

    Q_INVOKABLE void connectToRobot(const QString ip, const QString port);
private slots:
    void sessionOpened();
    void displayError(QAbstractSocket::SocketError socketError);
    void readMessage();
private:
    QTcpSocket *tcpSocket = nullptr;
    QDataStream in;
    QNetworkSession *networkSession = nullptr;

};

}
#endif // !ROBOT_CONTROLLER_H