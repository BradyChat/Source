/****************************************************************************
** Meta object code from reading C++ file 'nuovoutente.h'
**
** Created: Tue Mar 5 18:09:25 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "nuovoutente.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'nuovoutente.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_nuovoUtente[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      39,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_nuovoUtente[] = {
    "nuovoUtente\0\0on_btnIscriviti_clicked()\0"
    "on_btnRitorna_clicked()\0"
};

const QMetaObject nuovoUtente::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_nuovoUtente,
      qt_meta_data_nuovoUtente, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &nuovoUtente::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *nuovoUtente::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *nuovoUtente::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_nuovoUtente))
        return static_cast<void*>(const_cast< nuovoUtente*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int nuovoUtente::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_btnIscriviti_clicked(); break;
        case 1: on_btnRitorna_clicked(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
