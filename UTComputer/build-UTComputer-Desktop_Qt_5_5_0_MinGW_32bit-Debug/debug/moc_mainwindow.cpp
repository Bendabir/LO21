/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UTComputer/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "on0Pressed"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "on1Pressed"
QT_MOC_LITERAL(4, 34, 10), // "on2Pressed"
QT_MOC_LITERAL(5, 45, 10), // "on3Pressed"
QT_MOC_LITERAL(6, 56, 10), // "on4Pressed"
QT_MOC_LITERAL(7, 67, 10), // "on5Pressed"
QT_MOC_LITERAL(8, 78, 10), // "on6Pressed"
QT_MOC_LITERAL(9, 89, 10), // "on7Pressed"
QT_MOC_LITERAL(10, 100, 10), // "on8Pressed"
QT_MOC_LITERAL(11, 111, 10), // "on9Pressed"
QT_MOC_LITERAL(12, 122, 14), // "onCommaPressed"
QT_MOC_LITERAL(13, 137, 18), // "onBackspacePressed"
QT_MOC_LITERAL(14, 156, 20), // "appendLiteralInStack"
QT_MOC_LITERAL(15, 177, 4), // "save"
QT_MOC_LITERAL(16, 182, 4) // "load"

    },
    "MainWindow\0on0Pressed\0\0on1Pressed\0"
    "on2Pressed\0on3Pressed\0on4Pressed\0"
    "on5Pressed\0on6Pressed\0on7Pressed\0"
    "on8Pressed\0on9Pressed\0onCommaPressed\0"
    "onBackspacePressed\0appendLiteralInStack\0"
    "save\0load"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,
       7,    0,   94,    2, 0x0a /* Public */,
       8,    0,   95,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x0a /* Public */,
      10,    0,   97,    2, 0x0a /* Public */,
      11,    0,   98,    2, 0x0a /* Public */,
      12,    0,   99,    2, 0x0a /* Public */,
      13,    0,  100,    2, 0x0a /* Public */,
      14,    0,  101,    2, 0x0a /* Public */,
      15,    0,  102,    2, 0x0a /* Public */,
      16,    0,  103,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on0Pressed(); break;
        case 1: _t->on1Pressed(); break;
        case 2: _t->on2Pressed(); break;
        case 3: _t->on3Pressed(); break;
        case 4: _t->on4Pressed(); break;
        case 5: _t->on5Pressed(); break;
        case 6: _t->on6Pressed(); break;
        case 7: _t->on7Pressed(); break;
        case 8: _t->on8Pressed(); break;
        case 9: _t->on9Pressed(); break;
        case 10: _t->onCommaPressed(); break;
        case 11: _t->onBackspacePressed(); break;
        case 12: _t->appendLiteralInStack(); break;
        case 13: _t->save(); break;
        case 14: _t->load(); break;
        default: ;
        }
    }
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
    if (!strcmp(_clname, "Calculator"))
        return static_cast< Calculator*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
