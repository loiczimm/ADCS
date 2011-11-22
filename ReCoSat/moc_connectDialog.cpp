/****************************************************************************
** Meta object code from reading C++ file 'connectDialog.h'
**
** Created: Wed Nov 16 16:45:17 2011
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widget/core/connectDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connectDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConnectDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      49,   14,   14,   14, 0x0a,
      68,   14,   14,   14, 0x0a,
      84,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ConnectDialog[] = {
    "ConnectDialog\0\0currentConnectionTypeChanged(int)\0"
    "updateVisibility()\0saveAsDefault()\0"
    "saveCurrentAsProfile()\0"
};

void ConnectDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConnectDialog *_t = static_cast<ConnectDialog *>(_o);
        switch (_id) {
        case 0: _t->currentConnectionTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateVisibility(); break;
        case 2: _t->saveAsDefault(); break;
        case 3: _t->saveCurrentAsProfile(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ConnectDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConnectDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConnectDialog,
      qt_meta_data_ConnectDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConnectDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConnectDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConnectDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConnectDialog))
        return static_cast<void*>(const_cast< ConnectDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ConnectDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
