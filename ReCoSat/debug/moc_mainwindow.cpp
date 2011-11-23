/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed 23. Nov 18:28:04 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
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
     379,   11,   11,   11, 0x08,

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
    "updateCaption()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
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
        switch (_id) {
        case 0: openConnectDialog(); break;
        case 1: on_simulationButton_clicked(); break;
        case 2: on_roll_spinbox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: on_pitch_spinbox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: on_yaw_spinbox_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: on_roll_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: on_pitch_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: on_yaw_dial_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: updateQuaternions(); break;
        case 9: on_coarseAlignment_radiobutton_released(); break;
        case 10: on_fineAlignment_radiobutton_released(); break;
        case 11: updateCaption(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
