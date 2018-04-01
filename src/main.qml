import QtQuick 2.6
import QtQuick.Controls 2.1

ApplicationWindow {
    visible: true

    width: 1024
    height: 680
    title: qsTr("Robot Control Center")

    header: ToolBar {
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

    StackView {
        id: stackView
        anchors.fill: parent
        focus: true

        initialItem: Item {
            width: parent.width
            height: parent.height

            Column {
                spacing: 15
                Button {
                    text: qsTr("Connect")
                }
            }
        }
    }

}