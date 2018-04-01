#ifndef ROBOT_CONTROLLER_H
#define ROBOT_CONTROLLER_H

#include <QtCore/QObject>

namespace robot {

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    ~Controller();

private:
    
};

}
#endif // !ROBOT_CONTROLLER_H