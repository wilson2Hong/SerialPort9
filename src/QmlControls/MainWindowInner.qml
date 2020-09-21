import QtQuick          2.3
import QtQuick.Controls 1.2
import QtQuick.Dialogs  1.2
import QtQuick.Layouts 1.3

Item
{
        Rectangle{
            id:rootRectangle
            anchors.fill: parent
            color:  "#D3D3D3"
            property real margin: 5
                    Settings
                    {
                        id:  settingsRec
                        anchors.left:parent.left
                        anchors.top:parent.top
                    }

            }

}


