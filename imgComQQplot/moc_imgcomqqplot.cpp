/****************************************************************************
** Meta object code from reading C++ file 'imgcomqqplot.h'
**
** Created: Mon Dec 10 17:18:20 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "imgcomqqplot.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imgcomqqplot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_imgComQQplot[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      42,   13,   13,   13, 0x08,
      70,   13,   13,   13, 0x08,
     100,   13,   13,   13, 0x08,
     120,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_imgComQQplot[] = {
    "imgComQQplot\0\0on_pushButtonLoad_clicked()\0"
    "on_pushButtonHist_clicked()\0"
    "on_pushButtonQqPlot_clicked()\0"
    "on_chkCor_clicked()\0on_chkPval_clicked()\0"
};

void imgComQQplot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        imgComQQplot *_t = static_cast<imgComQQplot *>(_o);
        switch (_id) {
        case 0: _t->on_pushButtonLoad_clicked(); break;
        case 1: _t->on_pushButtonHist_clicked(); break;
        case 2: _t->on_pushButtonQqPlot_clicked(); break;
        case 3: _t->on_chkCor_clicked(); break;
        case 4: _t->on_chkPval_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData imgComQQplot::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject imgComQQplot::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_imgComQQplot,
      qt_meta_data_imgComQQplot, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &imgComQQplot::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *imgComQQplot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *imgComQQplot::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_imgComQQplot))
        return static_cast<void*>(const_cast< imgComQQplot*>(this));
    return QDialog::qt_metacast(_clname);
}

int imgComQQplot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
