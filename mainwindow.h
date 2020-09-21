#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QQuickWidget>
#include <QGridLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//bool setSource(const QUrl& qmlUrl);

private slots:


private:
    Ui::MainWindow *ui;

    QVBoxLayout*            _centralLayout;
};

#endif // MAINWINDOW_H


class Seriallink : public QObject
{
   Q_OBJECT
public:
    Q_PROPERTY(QString sendnumber READ sendnumber WRITE setsendnumber NOTIFY sendnumberChanged)//发送的数据字节统计
    Q_PROPERTY(QString receivedata READ receivedata WRITE setreceivedata NOTIFY receivedataChanged)//从串口收到的数据
//    Q_PROPERTY(QByteArray receivedata READ receivedata WRITE setreceivedata NOTIFY receivedataChanged)
    Q_PROPERTY(QStringList   serialPortStrings   READ serialPortStrings    NOTIFY commPortStringsChanged)
    Q_PROPERTY(QString receivenumber READ receivenumber WRITE setreceivenumber NOTIFY receivenumberChanged)//接收的数据字节统计
    Q_PROPERTY(int rec_testnumber READ rec_test_num WRITE set_test_num NOTIFY rec_test_Changed)

    Q_PROPERTY(bool is_connected READ rec_Connected WRITE set_Connected NOTIFY connect_state_Changed)

    struct Settings
    {
        QString name;
        qint32 baudRate;
        QSerialPort::DataBits dataBits;
        QSerialPort::Parity parity;
        QSerialPort::StopBits stopBits;
        QSerialPort::FlowControl flowControl;
    };


    Seriallink(QObject *parent = 0);
    ~Seriallink();

    bool rec_Connected();
    void set_Connected(bool is_connected);

    QString sendnumber();
    void setsendnumber(QString sendnumber);

    QString receivedata(void);
//    QByteArray receivedata(void);
    void setreceivedata(QString receivedata);
//    void setreceivedata(QByteArray receivedata);

    QString receivenumber();
    void setreceivenumber(QString receivenumber);

    int rec_test_num();
    void set_test_num(int rec_test_num);

   Q_INVOKABLE void _updateSerialPorts();
   Q_INVOKABLE void closePort();//关闭端口;

    static QString cleanPortDisplayname(const QString name);

    Q_INVOKABLE void openAndSetPort(QString Portname,int BaudRateIndex,int DatabitsIndex,int ParityIndex,int StopbitsIndex,int FlowcontrolIndex);//打开并设定端口;
    QStringList         serialPortStrings       (void);
    Q_INVOKABLE   void set_baud(QString baudrate);
    Q_INVOKABLE void sendto(QString sendmessage);//发送数据;
    Q_INVOKABLE void clearnumber();//数据统计清零;
    QByteArray data_pro;
signals:
   void connect_state_Changed();
    void rec_test_Changed();

    void sendnumberChanged();
    void receivedataChanged();
        void commPortStringsChanged();
        void receivenumberChanged();




public slots:
    void receivefrom();//信号（收到数据激发的信号）响应函数
private:
        QSerialPort *serial;
        QString m_receivedata;
        QString m_sendnumber = '0';
        QString m_receivenumber = '0';
        int m_test_num;
        QStringList _commPortDisplayList;
        QStringList _commPortList;
       bool connect_state = false;
};
