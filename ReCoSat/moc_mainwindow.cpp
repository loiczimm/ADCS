/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Nov 17 15:29:55 2011
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      32,   11,   11,   11, 0x08,
      67,   62,   11,   11, 0x08,
     104,   62,   11,   11, 0x08,
     142,   62,   11,   11, 0x08,
     184,  178,   11,   11, 0x08,
     215,  178,   11,   11, 0x08,
     247,  178,   11,   11, 0x08,
     277,   11,   11,   11, 0x08,
     297,   11,   11,   11, 0x08,
     339,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0openConnectDialog()\0"
    "on_simulationButton_clicked()\0arg1\0"
    "on_roll_spinbox_valueChanged(double)\0"
    "on_pitch_spinbox_valueChanged(double)\0"
    "on_yaw_spinbox_valueChanged(double)\0"
    "value\0on_roll_dial_valueChanged(int)\0"
    "on_pitch_dial_valueChanged(int)\0"
    "on_yaw_dial_valueChanged(int)\0"
    "updateQuaternions()\0"
    "on_coarseAlignment_radiobutton_released()\0"
    "on_fineAlignment_radiobutton_released()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->openConnectDialog(); break;
        case 1: _t->on_simulationButton_clicked(); break;
        case 2: _t->on_roll_spinbox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_pitch_spinbox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_yaw_spinbox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->on_roll_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_pitch_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_yaw_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->updateQuaternions(); break;
        case 9: _t->on_coarseAlignment_radiobutton_released(); break;
        case 10: _t->on_fineAlignment_radiobutton_released(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
