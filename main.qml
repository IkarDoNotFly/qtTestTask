import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15



ColumnLayout {
    anchors.fill: parent
    spacing: 6

    TextField {

        onTextChanged: cppModel.updateWildcard(text)

        Text {
            text:"type wildcard here"
            color: "#aaa"
            visible: !parent.text
        }
    }

    ListView {
        Layout.preferredWidth: parent.width
        model: cppModel
        Layout.fillWidth: true

        Layout.minimumHeight: 200
        delegate: Button {
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignLeft
            RowLayout {
                anchors.fill: parent
                spacing: 6
                Image {
                    Layout.maximumWidth: 32
                    Layout.maximumHeight: 32
                    source: image_path
                }
                Text {
                    text: name
                }
            }
            onClicked: console.log("calling", number, image_path)
        } // button
    } // listview
} // column

