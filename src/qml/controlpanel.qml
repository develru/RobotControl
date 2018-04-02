import QtQuick 2.6
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.1

Page {
    header: Label {
        text: "Control Panel"
        padding: 10
        font.pixelSize: 20
    }

    GroupBox {
        title: qsTr("Manual Control")
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        ColumnLayout {
            anchors.fill: parent
            Button {
                text: qsTr("Forward")
            }
        }
    }
}
