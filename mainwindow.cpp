#include "mainwindow.h"
#include "ui_mainwindow1.h"
#include <qquickwidget.h>
#include <QtQuick/QQuickView>
#include <QtQml>
Seriallink::Settings currentsetting;
QSerialPort serialtest;

qint64 c_sendnumber;
qint64 c_receivenumber = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(400,800);        //   窗口大小固定
    _centralLayout = new QVBoxLayout();
    _centralLayout->setContentsMargins(0, 0, 0, 0);
    centralWidget()->setLayout(_centralLayout);

    QQuickWidget *view = new QQuickWidget;
    _centralLayout->addWidget(view);
    view->setResizeMode(QQuickWidget::SizeRootObjectToView);//  控件随着窗户变化
    view->setSource(QStringLiteral("src/QmlControls/MainWindow.qml"));
     setWindowTitle(QStringLiteral("串口助手"));
     QApplication::setWindowIcon(QIcon(":/Img/qgroundcontrol.ico"));
     setDockOptions(0);
     setCorner(Qt::BottomRightCorner, Qt::BottomDockWidgetArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Seriallink::Seriallink(QObject* parent) :
    QObject(parent)
{
  QObject::connect(&serialtest, SIGNAL(readyRead()),this, SLOT(receivefrom()));//将端口收到数据产生的信号绑定receivefrom()函数;
}
Seriallink::~Seriallink()
{

}

void Seriallink::set_baud(QString baudrate)
{
    serial = new QSerialPort;
    serial->setBaudRate(baudrate.toInt());
}

void Seriallink::openAndSetPort(QString Portname,
                                int BaudRateIndex,
                                int DatabitsIndex,
                                int ParityIndex,
                                int StopbitsIndex,
                                int FlowcontrolIndex)
{
    //1.得到当前选择的各项设置
    //得到当前端口名
    currentsetting.name=Portname;//由qml里表示name的combobox的currentIndex来确定当前的name
//    std::cout<<" ok setPortName to "+ currentsetting.name.toStdString()<< std::endl;//通过输出来验证设定成功

    //得到当前波特率
    qint32 allbauRate[4]={9600,19200,57600,115200};
    currentsetting.baudRate=allbauRate[BaudRateIndex];

    //得到当前发送位数
    QSerialPort::DataBits allDatabits[4]={QSerialPort::Data5,
                                          QSerialPort::Data6,
                                          QSerialPort::Data7,
                                          QSerialPort::Data8};
    currentsetting.dataBits=allDatabits[DatabitsIndex];

    //得到当前Parity
    QSerialPort::Parity allparity[5]={QSerialPort::NoParity,
                                      QSerialPort::EvenParity,
                                      QSerialPort::OddParity,
                                      QSerialPort::MarkParity,
                                      QSerialPort::SpaceParity};
    currentsetting.parity=allparity[ParityIndex];

    //得到当前停止位
    QSerialPort::StopBits allstopBits[3]={QSerialPort::OneStop,
                                          QSerialPort::OneAndHalfStop,
                                          QSerialPort::TwoStop};
    currentsetting.stopBits=allstopBits[StopbitsIndex];

    //得到当前FlowControl
    QSerialPort::FlowControl allflowControl[3]={QSerialPort::NoFlowControl,
                                                QSerialPort::HardwareControl,
                                                QSerialPort::SoftwareControl};
    currentsetting.flowControl=allflowControl[FlowcontrolIndex];


//2.设定当前端口名
    serialtest.setPortName(currentsetting.name);

//3.打开这一端口并按照当前设置信息进行设置
    if (serialtest.open(QIODevice::ReadWrite))//打开这一端口
    {
//        std::cout<<"open port sucess"<<std::endl;

        if(serialtest.setBaudRate(currentsetting.baudRate)//设置各项信息
                && serialtest.setDataBits(currentsetting.dataBits)
                && serialtest.setParity(currentsetting.parity)
                && serialtest.setStopBits(currentsetting.stopBits)
                && serialtest.setFlowControl(currentsetting.flowControl))
        {
//            std::cout<<"set sucess"<<std::endl;
        }
    }
    set_Connected(serialtest.isOpen());

}



void Seriallink::sendto(QString sendmessage)//此函数由qml里的send按钮触发，sendmessage来源于qml文本框的当前文本，
{
//    QByteArray data = sendmessage.toLocal8Bit()+'\r';//将QString转为QByteArray，并加上'\r'（回车符）,因为芯片要求在回车符之后再返回数据
//    qint64 testwritenumber=serialtest.write(data);//写入数据
    qint64 testwritenumber=serialtest.write(sendmessage.toLocal8Bit());
    m_receivedata=m_receivedata+"\n";//加上换行符便于显示

    c_sendnumber=c_sendnumber+testwritenumber;//发送数据字节数统计（减去回车符）
    setsendnumber(QString ::number(c_sendnumber));//更新发送的数据字节总数
}

void Seriallink::setsendnumber(QString sendnumber)//更新发送的数据字节总数，触发sendnumberChanged()的消息响应函数sendnumber()来更新显示
{
    m_sendnumber=sendnumber;
    emit sendnumberChanged();
}

QString Seriallink::sendnumber()//响应sendnumberChanged()消息
{
    return m_sendnumber;
}

int state = 0;
void Seriallink::receivefrom()//由readyRead()消息出发（在前边进行绑定），当串口收到数据此消息被激活（对于串口，每发送出去一个字节，都会将此字节返回，触发readyread消息，当芯片有特殊指令时，收到的信息更多，比如对sim900，发送0000，芯片就会受到0000，但是发送AT，会受到 AT OK）
{
    QByteArray data = serialtest.readAll();//读取所有收到的数据
//    int buf_cal[20];
//    QString temp;
//    int weight;
//    bool ok;
    QString receivedata=data.data();//将QByteArray转为QString来显示
//    QByteArray receivedata =data.toHex();
    m_receivedata= m_receivedata+receivedata;//将某次收到的数据进行累加，因为如果不累加的话每次有readyread就会触发此函数，会重置m_receivedata，覆盖之前收到的数据
    emit receivedataChanged();//发送消息触发receivedata()，更新当前收到的数据显示receivedata
    qint64 testreadnumber=data.length();//接收数据字节数统计
    c_receivenumber=c_receivenumber+testreadnumber;
    setreceivenumber(QString ::number(c_receivenumber));//更新接收的数据字节总数
//0F 00 E4 1F A8 F9 07 16 00 02 10 2C 00 04 20 00 01 08 07 38 00 10 80 0C 14
//    if(!data.isEmpty())
//    {
//        for(int i =0;i< data.length();i++)
//        {
//            temp = QString(data.toHex()).mid(2*i,2);
//            weight= temp.toInt(&ok,16);
//            if(state==0)
//            {
//                 if(weight==0xFF)
//              {
//               buf_cal[0] = 0xFF;
//               state = 1;

//              }
//                   else
//               {
//                    state = 0;
//                }
//            }
//            else if(state==1)
//            {
//                if(weight==0xEE)
//                {
//                    buf_cal[1] = 0xEE;
//                    state = 2;
//                }
//                else
//                 {
//                   state = 0;
//                }
//            }
//            else if(state ==2)
//             {
//                set_test_num(weight);
//                state = 3;
//             }

//          }
//    }

//    if(state == 3)
//    {
//        state = 0;

//        QString receivedata =QStringLiteral("你好")+"\n";
//        //    QString receivedata=data.data();//将QByteArray转为QString来显示
//        //    QByteArray receivedata =data.toHex();
//            m_receivedata=m_receivedata+receivedata;
//        //    //将某次收到的数据进行累加，因为如果不累加的话每次有readyread就会触发此函数，会重置m_receivedata，覆盖之前收到的数据
//            emit receivedataChanged();//发送消息触发receivedata()，更新当前收到的数据显示receivedata
//            qint64 testreadnumber=data.length();//接收数据字节数统计
//            c_receivenumber=c_receivenumber+testreadnumber;
//            setreceivenumber(QString ::number(c_receivenumber));//更新接收的数据字节总数

//    }

}
void Seriallink::setreceivenumber(QString receivenumber)//更新接收的数据字节总数
{
    m_receivenumber=receivenumber;
    emit receivenumberChanged();;
}

QString Seriallink::receivenumber()//响应receivenumberChanged()消息
{
    return m_receivenumber;
}
void Seriallink::set_test_num(int rec_test_num)
{
    m_test_num = rec_test_num;
    emit rec_test_Changed();
}

int Seriallink::rec_test_num()
{
    return m_test_num;
}

void Seriallink::set_Connected(bool is_connected)
{
    connect_state = is_connected;
//
        emit connect_state_Changed();
}

bool Seriallink::rec_Connected()
{

    return connect_state;
}





QString Seriallink::receivedata()//qml读取receivedata值的时候就会触发此函数,或者emit receivedataChanged()更新当前收到的数据显示时触发
// QByteArray Seriallink::receivedata()
{
    return m_receivedata;
}

void Seriallink::setreceivedata(QString receivedata)//
//  void Seriallink::setreceivedata(QByteArray receivedata)   //其任务已被receive from函数完成，但是在清空数据时用到这个函数
{

    m_receivedata=receivedata;
    emit receivedataChanged();
}

QStringList Seriallink::serialPortStrings(void)
{
    if(!_commPortDisplayList.size())
    {
        _updateSerialPorts();
    }
    return _commPortDisplayList;

}

void Seriallink::_updateSerialPorts()
{
    _commPortList.clear();
    _commPortDisplayList.clear();

    QList<QSerialPortInfo> portList = QSerialPortInfo::availablePorts();
    foreach (const QSerialPortInfo &info, portList)
    {
        QString port = info.systemLocation().trimmed();
        _commPortList += port;
        _commPortDisplayList += cleanPortDisplayname(port);
    }
    emit commPortStringsChanged();
}

QString Seriallink::cleanPortDisplayname(const QString name)
{
    QString pname = name.trimmed();
#ifdef Q_OS_WIN
    pname.replace("\\\\.\\", "");
#else
    pname.replace("/dev/cu.", "");
    pname.replace("/dev/", "");
#endif
    return pname;
}

void Seriallink::clearnumber()//由按钮出发
{
    c_sendnumber=0;
    c_receivenumber=0;
}

void Seriallink::closePort()//由按钮出发
{
    serialtest.close();
   set_Connected(serialtest.isOpen());
}
