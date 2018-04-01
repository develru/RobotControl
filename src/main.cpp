#include <QtGui/QGuiApplication>
// #include <QtWidgets/QApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQuickControls2/QQuickStyle>

int main(int argc, char *argv[])
{
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    // QApplication app(argc, argv);
    QGuiApplication app(argc, argv);

    QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}