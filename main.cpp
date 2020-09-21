#include "mainwindow.h"
#include <QApplication>
#include <QtQml>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qmlRegisterType<Seriallink>  ("Seriallink.Controller", 1, 0, "Seriallink");

    MainWindow w;
    w.show();

    return a.exec();
}


