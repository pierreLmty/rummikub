/****************************************************************************
** Meta object code from reading C++ file 'vuechoixjoueur.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Vue/vuechoixjoueur.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vuechoixjoueur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vueChoixJoueur[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   15,   15,   15, 0x0a,
      58,   15,   15,   15, 0x0a,
      70,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_vueChoixJoueur[] = {
    "vueChoixJoueur\0\0name\0changeInterface(QString)\0"
    "nbJoueur2()\0nbJoueur3()\0nbJoueur4()\0"
};

void vueChoixJoueur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        vueChoixJoueur *_t = static_cast<vueChoixJoueur *>(_o);
        switch (_id) {
        case 0: _t->changeInterface((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->nbJoueur2(); break;
        case 2: _t->nbJoueur3(); break;
        case 3: _t->nbJoueur4(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vueChoixJoueur::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vueChoixJoueur::staticMetaObject = {
    { &vue::staticMetaObject, qt_meta_stringdata_vueChoixJoueur,
      qt_meta_data_vueChoixJoueur, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vueChoixJoueur::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vueChoixJoueur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vueChoixJoueur::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vueChoixJoueur))
        return static_cast<void*>(const_cast< vueChoixJoueur*>(this));
    return vue::qt_metacast(_clname);
}

int vueChoixJoueur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = vue::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void vueChoixJoueur::changeInterface(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
