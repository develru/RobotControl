import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1

Page {
    //Component.onCompleted: controller.sendCommand("DRVST")
    header: Label {
        text: "Control Panel"
        padding: 10
        font.pixelSize: 20
    }

    GroupBox {
        title: qsTr("Telemetric data")
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        ColumnLayout {
            Label {
                text: qsTr("Time without charging:")
            }
            Button {
                text: qsTr("Manual Control")
                onClicked: manualControl.visible = true
            }
        }
    }
    GroupBox {
        id: manualControl
        visible: false
        title: qsTr("Manual Control")
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        ColumnLayout {
            anchors.fill: parent
            Button {
                text: qsTr("Forwards")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    controller.sendCommand("DRVST")
                    controller.sendCommand("FW")
                }
            }
            RowLayout {
                spacing: 15
                Button {
                    text: qsTr("Left")
                    onClicked: controller.sendCommand("LT")
                }
                Button {
                    text: qsTr("Right")
                    onClicked: controller.sendCommand("RT")
                }
            }
            Button {
                text: qsTr("Backwards")
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: controller.sendCommand("BW")
            }
        }
    }
}
