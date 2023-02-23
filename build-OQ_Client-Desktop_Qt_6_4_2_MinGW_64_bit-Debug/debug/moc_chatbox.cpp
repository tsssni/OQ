/****************************************************************************
** Meta object code from reading C++ file 'chatbox.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../OQ_Client/chatbox.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatbox.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_ChatBox_t {
    uint offsetsAndSizes[20];
    char stringdata0[8];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[20];
    char stringdata5[12];
    char stringdata6[9];
    char stringdata7[8];
    char stringdata8[8];
    char stringdata9[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ChatBox_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ChatBox_t qt_meta_stringdata_ChatBox = {
    {
        QT_MOC_LITERAL(0, 7),  // "ChatBox"
        QT_MOC_LITERAL(8, 14),  // "on_add_clicked"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 15),  // "on_user_clicked"
        QT_MOC_LITERAL(40, 19),  // "on_settings_clicked"
        QT_MOC_LITERAL(60, 11),  // "readMessage"
        QT_MOC_LITERAL(72, 8),  // "timetemp"
        QT_MOC_LITERAL(81, 7),  // "mestemp"
        QT_MOC_LITERAL(89, 7),  // "dirtemp"
        QT_MOC_LITERAL(97, 11)   // "sendMessage"
    },
    "ChatBox",
    "on_add_clicked",
    "",
    "on_user_clicked",
    "on_settings_clicked",
    "readMessage",
    "timetemp",
    "mestemp",
    "dirtemp",
    "sendMessage"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ChatBox[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x0a,    1 /* Public */,
       3,    0,   45,    2, 0x0a,    2 /* Public */,
       4,    0,   46,    2, 0x0a,    3 /* Public */,
       5,    3,   47,    2, 0x0a,    4 /* Public */,
       9,    0,   54,    2, 0x0a,    8 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime, QMetaType::QString, QMetaType::Bool,    6,    7,    8,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ChatBox::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ChatBox.offsetsAndSizes,
    qt_meta_data_ChatBox,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ChatBox_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ChatBox, std::true_type>,
        // method 'on_add_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_user_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_settings_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDateTime, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'sendMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ChatBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChatBox *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_add_clicked(); break;
        case 1: _t->on_user_clicked(); break;
        case 2: _t->on_settings_clicked(); break;
        case 3: _t->readMessage((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3]))); break;
        case 4: _t->sendMessage(); break;
        default: ;
        }
    }
}

const QMetaObject *ChatBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatBox::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChatBox.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ChatBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
