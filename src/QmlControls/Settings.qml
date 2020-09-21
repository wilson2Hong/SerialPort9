import QtQuick          2.3
import QtQuick.Controls 1.2
import QtQuick.Dialogs  1.2
import QtQuick.Layouts 1.3
import Seriallink.Controller 1.0

Item{
    property real defaultFontPixelHeight:   100
    property real defaultspace:    12
    property bool connected:   seriaport.is_connected
    width:      parent.width
    height:     parent.height
    Seriallink{id: seriaport}
        Rectangle
        {
              id:        blackRec
              radius:     width * 0.1
              anchors.fill:  parent
              border.color:  "Grey"
              border.width: 1
              color:   "LemonChiffon"
              anchors.margins:defaultspace
        }
        Column{
                    id:leftColumn
                    spacing: 10
                    anchors.fill:  parent
                    anchors.margins:20
                    //串口设置
                    Label{
                        text: qsTr("配  置")
                        color: "black"
                        font.bold: true
                        font.pointSize:   12
                        font.family: "仿宋"
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                GridLayout {
                    id: grid
                    columns: 2
                    rowSpacing: 5
                    anchors.horizontalCenter: parent.horizontalCenter
                    Label {
                        text: qsTr("串口:")
                        font.bold: true
                        font.pointSize:   11
                        font.family: "楷体"
                    }

                    ComboBox {
                        id :firstcombo
                        model: seriaport.serialPortStrings

                    }
                    Label {
                        text: qsTr("波特率")
                        font.bold: true
                        font.pointSize:   11
                        font.family: "楷体"
                    }
                    ComboBox {
                        id:baudRate
                        model: [ "9600", "19200", "57600","115200"]
                        onActivated: {
                            seriaport.set_baud(currentText)
                        }
                    }

                    Label{
                        text: "奇偶校验:"
                        font.bold: true
                        font.pointSize:   11
                        font.family: "楷体"
                    }
                    ComboBox {
                        id:parity
                        width:firstcombo.width
                        currentIndex: 0
                        model: [ "None", "Even", "Odd", "Mark", "Space" ]
                    }
                    Label{
                        text: "数据位:"
                        font.bold: true
                        font.pointSize:   11
                        font.family: "楷体"
                    }
                    ComboBox {
                        id:dataBits
                        width:firstcombo.width
                        currentIndex: 3
                        model: [ "5", "6", "7", "8" ]
                    }

                    Label{
                        text: "停止位:"
                        font.bold: true
                        font.pointSize:   11
                        font.family: "楷体"
                    }
                    ComboBox {
                        id:stopBits
                        width:firstcombo.width
                        currentIndex: 0
                        model: [ "1", "1.5", "2" ]
                    }
                    Label{
                        height: 20
                        text: "流控:"
                        font.bold: true
                        font.pointSize:   11
                        font.family: "楷体"
                    }
                    ComboBox {
                        id:flowControl
                        currentIndex: 0
                        width:firstcombo.width*3
                        model: [ "None", "RTS/CTS", "XON/XOFF" ]
                    }

               }

                Row{
                    spacing:  10
                    anchors.horizontalCenter: parent.horizontalCenter
                       MenuButton{
                           text:"刷新"
                          imageResource: "qrc:/Img/ButtonImage.png"
                          onClicked:
                          {
                              seriaport._updateSerialPorts();
                          }

                       }
                        MenuButton{
                            text: "连接"
                            imageResource: "qrc:/Img/ButtonImage.png"
                            onClicked: {
                                seriaport.openAndSetPort(seriaport.serialPortStrings[firstcombo.currentIndex],baudRate.currentIndex,dataBits.currentIndex
                                                          ,parity.currentIndex,stopBits.currentIndex,flowControl.currentIndex)
                            }
                            visible:!connected
                        }
                        MenuButton{
                            imageResource: "qrc:/Img/Disconnect.svg"
                            text: "断开"
                            visible: connected
                                onClicked: {
                                    seriaport.closePort()//关闭串口
                                       }
                            }
                     }

                Rectangle
                {
                      id:        splitRec1
                      color:   "Grey"
                      width:   parent.width
                      height: 1.5
                }


                Label{
                       text: qsTr("发  送")
                       color: "black"
                       font.bold: true
                       font.pointSize:   12
                       font.family: "仿宋"
                       anchors.horizontalCenter: parent.horizontalCenter
                     }

                    TextField {
                                    id: textInput1
                                    width: parent.width
                                    height: 40
                                    placeholderText: qsTr("输入***")
                                    font.pixelSize: 12
                             }

                  Row{
                      spacing:  10
                      anchors.horizontalCenter: parent.horizontalCenter
                          MenuButton{
                                    id:sendData
                                    text: qsTr("发送")
                                    imageResource: "qrc:/Img/ButtonImage.png"
                                    onClicked: {
                                        seriaport.sendto(textInput1.text);//触发发送数据函数
                                              }
                                        }
                          MenuButton{
                                    id:clearData
                                     text: qsTr("清除")
                                    imageResource: "qrc:/Img/ButtonImage.png"
                                    onClicked: {
                                                 textInput1.text ="";//清除
                                              }
                                       }
                     }
                  Label{
                          id:sendlabel
                          font.bold: true
                          text: qsTr("发送字节数:")+seriaport.sendnumber //显示发送数据计数
                       }
                  Rectangle
                  {
                        id:        splitRec2
                        color:   "Grey"
                        width:   parent.width
                        height: 1.5
                  }
                  Label{
                         text: qsTr("接  收")
                         color: "black"
                         font.bold: true
                         font.pointSize:   12
                         font.family: "仿宋"
                         anchors.horizontalCenter: parent.horizontalCenter
                       }
                   TextArea {
                             width: parent.width
                             id:                consoleEditor
                             Layout.fillHeight: true
                             property int maxLength: consoleEditor.width
                             wrapMode:         Text.Wrap
                             readOnly:          true
                             text:              seriaport.receivedata

                            }
                   Row{
                         spacing:  40
                               Label{
                                               color: "black"
                                               font.bold: true
                                               text: "接收字节数: "+seriaport.receivenumber//显示接收数据计数
                                   }
                               MenuButton
                                {

                                   text: "清除"
                                   imageResource: "qrc:/Img/ButtonImage.png"
                                   onClicked: {//清空接收数据显示，将数据计数清零
                                                       seriaport.receivedata=""
                                                       seriaport.sendnumber="0"
                                                       seriaport.receivenumber="0"
                                                       seriaport.clearnumber();
                                               }
                                 }


                     }


           }



}

