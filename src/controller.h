#ifndef ROBOT_CONTROLLER_H
#define ROBOT_CONTROLLER_H

#include <QtCore/QObject>
#include <QtCore/QString>

namespace robot {

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    ~Controller();

    Q_INVOKABLE void connect(const QString ip, const QString port);
private:
    
};

}
#endif // !ROBOT_CONTROLLER_H