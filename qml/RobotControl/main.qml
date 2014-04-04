import QtQuick 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1

import com.develru.prc 1.0

ApplicationWindow {

    property int margin: 11
    width: mainLayout.implicitWidth + 2 * margin
    height: mainLayout.implicitHeight + 2 * margin
    minimumWidth: mainLayout.Layout.minimumWidth + 2 * margin
    minimumHeight: mainLayout.Layout.minimumHeight + 2 * margin

    title: qsTr("Control Center")
    //    width: 640
    //    height: 480

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

    RowLayout {
        id: mainLayout
        anchors.fill: parent
        anchors.margins: margin
        ColumnLayout {
            Button {
                text: qsTr("Connect")
                Layout.fillWidth: true
                onClicked: con.connectToRobot();
            }
            Button {
                text: qsTr("Send")
                enabled: con.sendEnable
                Layout.fillWidth: true
                onClicked: con.sendMessage(tf_message.text);
            }
        }

        GridLayout {
            rows: 2
            columns: 2
            //flow: GridLayout.TopToBottom
//            anchors.fill: parent
            Label {
                text: "Message"
                Layout.fillWidth: true
            }
            TextField {
                id: tf_message
                Layout.fillWidth: true
            }
                TextArea {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.columnSpan: 2
                    text: con.logMsg
                }
        }
    }
}
