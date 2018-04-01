#include <QtCore/QDebug>

#include "controller.h"

using namespace robot;

Controller::Controller(QObject *parent) : 
    QObject(parent)
{

}

Controller::~Controller()
{

}

void Controller::connect(const QString ip, const QString port)
{
    qDebug() << ip << ":" << port;
}