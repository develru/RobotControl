import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true

    width: 1024
    height: 680
    title: qsTr("Robot Control Center")

    toolBar: ToolBar {
        // Label{
        //     text: "Test"
        // }
        ToolButton {
            height: parent.height
            anchors.right: parent.right
            text: qsTr("Quit")
            onClicked: Qt.quit()
        }
    }

}