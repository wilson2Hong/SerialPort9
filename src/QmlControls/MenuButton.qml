import QtQuick                  2.3
import QtQuick.Controls         1.2
import QtQuick.Controls.Styles  1.4
import QtGraphicalEffects       1.0

//import QGroundControl.Palette       1.0
//import QGroundControl.ScreenTools   1.0

Button {
    id:             _rootButton
    property real defaultFontPixelWidth:    10
    property real defaultFontPixelHeight:   10
    property bool   setupComplete:  true                                    ///< true: setup complete indicator shows as completed
    property bool   setupIndicator: true                                    ///< true: show setup complete indicator
    property string imageResource:  "/qmlimages/subMenuButtonImage.png"     ///< Button image
    text: "Button"

    checkable:      true
    implicitHeight: defaultFontPixelHeight * 3
    implicitWidth:  __panel.implicitWidth*1.3

    style: ButtonStyle {
        id: buttonStyle
        property bool showHighlight: control.pressed |  control.hovered
        background: Rectangle {
            id:     innerRect
            color:   showHighlight? "lightblue":"Dimgrey"

            implicitWidth: titleBar.x + titleBar.contentWidth + defaultFontPixelWidth

            ColoredImage {
                id:                     image
                anchors.leftMargin:     defaultFontPixelWidth
                anchors.left:           parent.left
                anchors.verticalCenter: parent.verticalCenter
                width:                  defaultFontPixelHeight * 2
                height:                 defaultFontPixelHeight * 2
                fillMode:               Image.PreserveAspectFit
                mipmap:                 true
                color:                   showHighlight? "red": "white"
                source:                 control.imageResource
                sourceSize:             _rootButton.sourceSize
            }

           Label {
                id:                     titleBar
                anchors.leftMargin:     defaultFontPixelWidth
                anchors.left:           image.right
                anchors.verticalCenter: parent.verticalCenter
                verticalAlignment:      TextEdit.AlignVCenter
                color:                   showHighlight? "black":"white"
                text:                   control.text
            }
        }

        label: Item {}
    }
}
