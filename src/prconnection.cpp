#include "prconnection.h"

PRConnection::PRConnection(QObject *parent) :
    QObject(parent),
    m_host("localhost"),
    m_port(9999)
{
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
