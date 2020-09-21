import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3

Rectangle {
    id:root
    property bool showSend: false
    property bool repeatSend: false
    ColumnLayout{
        anchors.fill: parent
        Rectangle {
            id: receiveData
            anchors.top: parent.top
            anchors.left: parent.left
            border.color: "#d7cfcf"
            height: parent.height/1.5
            width: parent.width

            Flickable {
                id: flickReceive
                anchors.fill: parent
                clip: true
                anchors.margins: 5

                function ensureVisible(r)
                {
                    if (contentX >= r.x)
                        contentX = r.x;
                    else if (contentX+width <= r.x+r.width)
                        contentX = r.x+r.width-width;
                    if (contentY >= r.y)
                        contentY = r.y;
                    else if (contentY+height <= r.y+r.height)
                        contentY = r.y+r.height-height;
                }

                TextEdit {
                    id: editReceive
                    width: flickReceive.width
                    focus: false
                    wrapMode: TextEdit.Wrap
                    onCursorRectangleChanged: flickReceive.ensureVisible(cursorRectangle)
                }

            }
        }

        Rectangle {
            id: sendData
            width: parent.width
            height: parent.height-receiveData.height-buttons.height
            border.color: "#d7cfcf"
            anchors.top: receiveData.bottom
            Flickable {
                id: flickSend
                anchors.fill: parent
                clip: true
                anchors.margins: 5

                function ensureVisible(r)
                {
                    if (contentX >= r.x)
                        contentX = r.x;
                    else if (contentX+width <= r.x+r.width)
                        contentX = r.x+r.width-width;
                    if (contentY >= r.y)
                        contentY = r.y;
                    else if (contentY+height <= r.y+r.height)
                        contentY = r.y+r.height-height;
                }

                TextEdit {
                    id: editSend
                    width: flickSend.width
                    focus: true
                    wrapMode: TextEdit.Wrap
                    onCursorRectangleChanged: flickSend.ensureVisible(cursorRectangle)
                }
            }
        }

    }
    RowLayout{
        id:buttons
        anchors.bottom: root.bottom
        anchors.right: root.right
        Button{
            text: "打开"
            onClicked: {
                serial.connect()
            }
        }
        Button{
            text: "关闭"
            onClicked: {
                serial.disConnect()
            }
        }
        Button{
            text: "发送"
            onClicked: {
                serial.sendString(editSend.text)
                console.log("send"+showSend)
                if(showSend)
                    editReceive.append(editSend.text)
            }
        }
    }
    Connections{
        target: serial
        onStringReceived:{
            editReceive.append(receiveString)
            console.log("receive:"+receiveString)
        }
    }

}