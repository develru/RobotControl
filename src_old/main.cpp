#include <QtQml>

#include "qtquick2controlsapplicationviewer.h"
#include "src/prconnection.h"

int main(int argc, char *argv[])
{
    Application app(argc, argv);

    QtQuick2ControlsApplicationViewer viewer;

    // Register the class
    qmlRegisterType<PRConnection>("com.develru.prc", 1, 0, "PRCConnection");

    viewer.setMainQmlFile(QStringLiteral("qml/RobotControl/main.qml"));
    viewer.show();

    return app.exec();
}
