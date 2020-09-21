
QT       += core gui
QT       += serialport
QT += \
    concurrent \
    gui \
    opengl \
    qml \
    quick \
    quickwidgets \
    sql \
    svg \
    widgets \
    xml\
    qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialPort
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow1.ui \



RESOURCES += \
    qml.qrc
//OTHER_FILES +=qml/Settings.qml

DISTFILES += \
    src/QmlControls/Settings.qml \
    src/QmlControls/MainWindowInner.qml \
    src/QmlControls/ColoredImage.qml \
    src/QmlControls/MenuButton.qml \
    src/QmlControls/MainWindow.qml
