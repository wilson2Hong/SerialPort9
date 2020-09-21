import QtQuick          2.3
import QtQuick.Controls 1.2
import QtQuick.Dialogs  1.2

Item {


    Loader {
        id:             mainWindowInner
        anchors.fill:   parent
        source:         "MainWindowInner.qml"

        Connections {
            target: mainWindowInner.item
        }
    }
}

