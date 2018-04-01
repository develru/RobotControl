import QtQuick 2.6
import QtQuick.Controls 2.1
import QtQuick.Controls.Material 2.1

ApplicationWindow {
    visible: true

    Material.theme: Material.Dark
    Material.accent: Material.DeepOrange

    width: 1024
    height: 680
    title: qsTr("Robot Control Center")

    header: ToolBar {
        Material.background: Material.BlueGrey
        ToolButton {
            Material.foreground: Material.DeepOrange
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
                anchors.centerIn: parent
                Label {
                    text: qsTr("IP address:")
                }
                TextField {
                    id: "ipAddress"
                }
                Label { text: qsTr("port") }
                TextField { id: port }
                Button {
                    text: qsTr("Connect")
                    Material.background: Material.DeepOrange
                    anchors.right: parent.right
                }
            }
        }
    }

}