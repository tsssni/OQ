/****************************************************************************
** Meta object code from reading C++ file 'oqsocket.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../OQ_Client/oqsocket.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'oqsocket.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_OQSocket_t {
    uint offsetsAndSizes[14];
    char stringdata0[9];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[4];
    char stringdata5[10];
    char stringdata6[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_OQSocket_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_OQSocket_t qt_meta_stringdata_OQSocket = {
    {
        QT_MOC_LITERAL(0, 8),  // "OQSocket"
        QT_MOC_LITERAL(9, 13),  // "handleMessage"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 21),  // "QMap<QString,QString>"
        QT_MOC_LITERAL(46, 3),  // "msg"
        QT_MOC_LITERAL(50, 9),  // "OQSocket*"
        QT_MOC_LITERAL(60, 14)   // "receiveMessage"
    },
    "OQSocket",
    "handleMessage",
    "",
    "QMap<QString,QString>",
    "msg",
    "OQSocket*",
    "receiveMessage"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_OQSocket[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   31,    2, 0x08,    4 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject OQSocket::staticMetaObject = { {
    QMetaObject::SuperData::link<QTcpSocket::staticMetaObject>(),
    qt_meta_stringdata_OQSocket.offsetsAndSizes,
    qt_meta_data_OQSocket,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_OQSocket_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<OQSocket, std::true_type>,
        // method 'handleMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMap<QString,QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<OQSocket *, std::false_type>,
        // method 'receiveMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void OQSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OQSocket *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->handleMessage((*reinterpret_cast< std::add_pointer_t<QMap<QString,QString>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<OQSocket*>>(_a[2]))); break;
        case 1: _t->receiveMessage(); break;
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
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OQSocket::*)(QMap<QString,QString> , OQSocket * );
            if (_t _q_method = &OQSocket::handleMessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *OQSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OQSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OQSocket.stringdata0))
        return static_cast<void*>(this);
    return QTcpSocket::qt_metacast(_clname);
}

int OQSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void OQSocket::handleMessage(QMap<QString,QString> _t1, OQSocket * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
