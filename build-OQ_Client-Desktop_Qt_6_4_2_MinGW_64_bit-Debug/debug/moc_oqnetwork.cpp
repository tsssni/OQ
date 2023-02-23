/****************************************************************************
** Meta object code from reading C++ file 'oqnetwork.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../OQ_Client/oqnetwork.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'oqnetwork.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_OQNetwork_t {
    uint offsetsAndSizes[14];
    char stringdata0[10];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[4];
    char stringdata5[10];
    char stringdata6[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_OQNetwork_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_OQNetwork_t qt_meta_stringdata_OQNetwork = {
    {
        QT_MOC_LITERAL(0, 9),  // "OQNetwork"
        QT_MOC_LITERAL(10, 13),  // "handleMessage"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 21),  // "QMap<QString,QString>"
        QT_MOC_LITERAL(47, 3),  // "msg"
        QT_MOC_LITERAL(51, 9),  // "OQSocket*"
        QT_MOC_LITERAL(61, 6)   // "socket"
    },
    "OQNetwork",
    "handleMessage",
    "",
    "QMap<QString,QString>",
    "msg",
    "OQSocket*",
    "socket"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_OQNetwork[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   20,    2, 0x0a,    1 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject OQNetwork::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_OQNetwork.offsetsAndSizes,
    qt_meta_data_OQNetwork,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_OQNetwork_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<OQNetwork, std::true_type>,
        // method 'handleMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMap<QString,QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<OQSocket *, std::false_type>
    >,
    nullptr
} };

void OQNetwork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OQNetwork *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handleMessage((*reinterpret_cast< std::add_pointer_t<QMap<QString,QString>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<OQSocket*>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< OQSocket* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *OQNetwork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OQNetwork::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OQNetwork.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int OQNetwork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
