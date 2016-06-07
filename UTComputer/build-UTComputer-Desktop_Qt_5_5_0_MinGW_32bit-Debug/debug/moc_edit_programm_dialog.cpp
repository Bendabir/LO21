/****************************************************************************
** Meta object code from reading C++ file 'edit_programm_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UTComputer/edit_programm_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'edit_programm_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EditProgrammDialog_t {
    QByteArrayData data[8];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditProgrammDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditProgrammDialog_t qt_meta_stringdata_EditProgrammDialog = {
    {
QT_MOC_LITERAL(0, 0, 18), // "EditProgrammDialog"
QT_MOC_LITERAL(1, 19, 7), // "isShown"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "showAtomContent"
QT_MOC_LITERAL(4, 44, 19), // "updateVariablesList"
QT_MOC_LITERAL(5, 64, 12), // "improvedShow"
QT_MOC_LITERAL(6, 77, 12), // "editVariable"
QT_MOC_LITERAL(7, 90, 11) // "enableApply"

    },
    "EditProgrammDialog\0isShown\0\0showAtomContent\0"
    "updateVariablesList\0improvedShow\0"
    "editVariable\0enableApply"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditProgrammDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EditProgrammDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditProgrammDialog *_t = static_cast<EditProgrammDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->isShown(); break;
        case 1: _t->showAtomContent(); break;
        case 2: _t->updateVariablesList(); break;
        case 3: _t->improvedShow(); break;
        case 4: _t->editVariable(); break;
        case 5: _t->enableApply(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EditProgrammDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EditProgrammDialog::isShown)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject EditProgrammDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EditProgrammDialog.data,
      qt_meta_data_EditProgrammDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EditProgrammDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditProgrammDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EditProgrammDialog.stringdata0))
        return static_cast<void*>(const_cast< EditProgrammDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int EditProgrammDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void EditProgrammDialog::isShown()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
