/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10) // "MainWindow"

    },
    "MainWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_Seriallink_t {
    QByteArrayData data[29];
    char stringdata0[400];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Seriallink_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Seriallink_t qt_meta_stringdata_Seriallink = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Seriallink"
QT_MOC_LITERAL(1, 11, 21), // "connect_state_Changed"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 16), // "rec_test_Changed"
QT_MOC_LITERAL(4, 51, 17), // "sendnumberChanged"
QT_MOC_LITERAL(5, 69, 18), // "receivedataChanged"
QT_MOC_LITERAL(6, 88, 22), // "commPortStringsChanged"
QT_MOC_LITERAL(7, 111, 20), // "receivenumberChanged"
QT_MOC_LITERAL(8, 132, 11), // "receivefrom"
QT_MOC_LITERAL(9, 144, 18), // "_updateSerialPorts"
QT_MOC_LITERAL(10, 163, 9), // "closePort"
QT_MOC_LITERAL(11, 173, 14), // "openAndSetPort"
QT_MOC_LITERAL(12, 188, 8), // "Portname"
QT_MOC_LITERAL(13, 197, 13), // "BaudRateIndex"
QT_MOC_LITERAL(14, 211, 13), // "DatabitsIndex"
QT_MOC_LITERAL(15, 225, 11), // "ParityIndex"
QT_MOC_LITERAL(16, 237, 13), // "StopbitsIndex"
QT_MOC_LITERAL(17, 251, 16), // "FlowcontrolIndex"
QT_MOC_LITERAL(18, 268, 8), // "set_baud"
QT_MOC_LITERAL(19, 277, 8), // "baudrate"
QT_MOC_LITERAL(20, 286, 6), // "sendto"
QT_MOC_LITERAL(21, 293, 11), // "sendmessage"
QT_MOC_LITERAL(22, 305, 11), // "clearnumber"
QT_MOC_LITERAL(23, 317, 10), // "sendnumber"
QT_MOC_LITERAL(24, 328, 11), // "receivedata"
QT_MOC_LITERAL(25, 340, 17), // "serialPortStrings"
QT_MOC_LITERAL(26, 358, 13), // "receivenumber"
QT_MOC_LITERAL(27, 372, 14), // "rec_testnumber"
QT_MOC_LITERAL(28, 387, 12) // "is_connected"

    },
    "Seriallink\0connect_state_Changed\0\0"
    "rec_test_Changed\0sendnumberChanged\0"
    "receivedataChanged\0commPortStringsChanged\0"
    "receivenumberChanged\0receivefrom\0"
    "_updateSerialPorts\0closePort\0"
    "openAndSetPort\0Portname\0BaudRateIndex\0"
    "DatabitsIndex\0ParityIndex\0StopbitsIndex\0"
    "FlowcontrolIndex\0set_baud\0baudrate\0"
    "sendto\0sendmessage\0clearnumber\0"
    "sendnumber\0receivedata\0serialPortStrings\0"
    "receivenumber\0rec_testnumber\0is_connected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Seriallink[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       6,  108, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    0,   83,    2, 0x06 /* Public */,
       7,    0,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   85,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       9,    0,   86,    2, 0x02 /* Public */,
      10,    0,   87,    2, 0x02 /* Public */,
      11,    6,   88,    2, 0x02 /* Public */,
      18,    1,  101,    2, 0x02 /* Public */,
      20,    1,  104,    2, 0x02 /* Public */,
      22,    0,  107,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   12,   13,   14,   15,   16,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void,

 // properties: name, type, flags
      23, QMetaType::QString, 0x00495003,
      24, QMetaType::QString, 0x00495003,
      25, QMetaType::QStringList, 0x00495001,
      26, QMetaType::QString, 0x00495003,
      27, QMetaType::Int, 0x00495003,
      28, QMetaType::Bool, 0x00495003,

 // properties: notify_signal_id
       2,
       3,
       4,
       5,
       1,
       0,

       0        // eod
};

void Seriallink::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Seriallink *_t = static_cast<Seriallink *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connect_state_Changed(); break;
        case 1: _t->rec_test_Changed(); break;
        case 2: _t->sendnumberChanged(); break;
        case 3: _t->receivedataChanged(); break;
        case 4: _t->commPortStringsChanged(); break;
        case 5: _t->receivenumberChanged(); break;
        case 6: _t->receivefrom(); break;
        case 7: _t->_updateSerialPorts(); break;
        case 8: _t->closePort(); break;
        case 9: _t->openAndSetPort((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 10: _t->set_baud((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->sendto((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->clearnumber(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Seriallink::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Seriallink::connect_state_Changed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Seriallink::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Seriallink::rec_test_Changed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Seriallink::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Seriallink::sendnumberChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Seriallink::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Seriallink::receivedataChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Seriallink::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Seriallink::commPortStringsChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Seriallink::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Seriallink::receivenumberChanged)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Seriallink *_t = static_cast<Seriallink *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->sendnumber(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->receivedata(); break;
        case 2: *reinterpret_cast< QStringList*>(_v) = _t->serialPortStrings(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->receivenumber(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->rec_test_num(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->rec_Connected(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Seriallink *_t = static_cast<Seriallink *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setsendnumber(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setreceivedata(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setreceivenumber(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->set_test_num(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->set_Connected(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Seriallink::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Seriallink.data,
      qt_meta_data_Seriallink,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Seriallink::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Seriallink::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Seriallink.stringdata0))
        return static_cast<void*>(const_cast< Seriallink*>(this));
    return QObject::qt_metacast(_clname);
}

int Seriallink::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Seriallink::connect_state_Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Seriallink::rec_test_Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Seriallink::sendnumberChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Seriallink::receivedataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Seriallink::commPortStringsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void Seriallink::receivenumberChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
