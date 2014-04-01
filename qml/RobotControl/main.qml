import QtQuick 2.1
import QtQuick.Controls 1.0

import com.develru.prc 1.0

ApplicationWindow {
    title: qsTr("Control Center")
    width: 640
    height: 480

    PRCConnection {
        id: con
        host: "localhost"
        port: 9999
    }

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    Button {
        text: qsTr("Connect")
        anchors.centerIn: parent
        onClicked: con.connectToRobot();
    }
}
