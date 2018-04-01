#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQuickControls2/QQuickStyle>
#include <QtQml/QQmlContext>
#include "controller.h"

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    // QApplication app(argc, argv);
    QGuiApplication app(argc, argv);

    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
    robot::Controller cont;
    engine.rootContext()->setContextProperty("controller", &cont);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}