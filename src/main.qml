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
        Label {
            id: toolBarText
            text: qsTr("Connect to the robot")
            font.pixelSize: 20
            anchors.centerIn: parent
        }
        ToolButton {
            Material.foreground: Material.Brown
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
            Page {
                anchors.centerIn: parent
                header: Label {
                    padding: 10
                    text: qsTr("Conect to the robot")
                    font.pixelSize: 20
                }
                Column {
                    spacing: 15
                    anchors.centerIn: parent
                    Label {
                        text: qsTr("IP address or Name:")
                    }
                    TextField {
                        id: "ipAddress"
                        text: "robotpi"
                    }
                    Label { text: qsTr("port") }
                    TextField {
                        id: port
                        text: "9999"
                    }
                    Button {
                        text: qsTr("Connect")
                        Material.background: Material.DeepOrange
                        anchors.right: parent.right
                        onClicked: {
                            toolBarText.text = qsTr("Control Panel")
                            stackView.push("qrc:/qml/controlpanel.qml")
                            controller.connectToRobot(ipAddress.text, port.text)
                        }
                    }
                }
            }
        }
    }

}
