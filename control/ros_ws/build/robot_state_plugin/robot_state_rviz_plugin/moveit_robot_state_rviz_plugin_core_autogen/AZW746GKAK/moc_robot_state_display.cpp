/****************************************************************************
** Meta object code from reading C++ file 'robot_state_display.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "include/moveit/robot_state_rviz_plugin/robot_state_display.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robot_state_display.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_moveit_rviz_plugin__RobotStateDisplay_t {
    QByteArrayData data[13];
    char stringdata0[300];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_moveit_rviz_plugin__RobotStateDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_moveit_rviz_plugin__RobotStateDisplay_t qt_meta_stringdata_moveit_rviz_plugin__RobotStateDisplay = {
    {
QT_MOC_LITERAL(0, 0, 37), // "moveit_rviz_plugin::RobotStat..."
QT_MOC_LITERAL(1, 38, 23), // "changedRobotDescription"
QT_MOC_LITERAL(2, 62, 0), // ""
QT_MOC_LITERAL(3, 63, 19), // "changedRootLinkName"
QT_MOC_LITERAL(4, 83, 22), // "changedRobotSceneAlpha"
QT_MOC_LITERAL(5, 106, 24), // "changedAttachedBodyColor"
QT_MOC_LITERAL(6, 131, 21), // "changedHighlightColor"
QT_MOC_LITERAL(7, 153, 23), // "changedUnhighlightColor"
QT_MOC_LITERAL(8, 177, 22), // "changedRobotStateTopic"
QT_MOC_LITERAL(9, 200, 26), // "changedEnableLinkHighlight"
QT_MOC_LITERAL(10, 227, 26), // "changedEnableVisualVisible"
QT_MOC_LITERAL(11, 254, 29), // "changedEnableCollisionVisible"
QT_MOC_LITERAL(12, 284, 15) // "changedAllLinks"

    },
    "moveit_rviz_plugin::RobotStateDisplay\0"
    "changedRobotDescription\0\0changedRootLinkName\0"
    "changedRobotSceneAlpha\0changedAttachedBodyColor\0"
    "changedHighlightColor\0changedUnhighlightColor\0"
    "changedRobotStateTopic\0"
    "changedEnableLinkHighlight\0"
    "changedEnableVisualVisible\0"
    "changedEnableCollisionVisible\0"
    "changedAllLinks"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_moveit_rviz_plugin__RobotStateDisplay[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void moveit_rviz_plugin::RobotStateDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RobotStateDisplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changedRobotDescription(); break;
        case 1: _t->changedRootLinkName(); break;
        case 2: _t->changedRobotSceneAlpha(); break;
        case 3: _t->changedAttachedBodyColor(); break;
        case 4: _t->changedHighlightColor(); break;
        case 5: _t->changedUnhighlightColor(); break;
        case 6: _t->changedRobotStateTopic(); break;
        case 7: _t->changedEnableLinkHighlight(); break;
        case 8: _t->changedEnableVisualVisible(); break;
        case 9: _t->changedEnableCollisionVisible(); break;
        case 10: _t->changedAllLinks(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject moveit_rviz_plugin::RobotStateDisplay::staticMetaObject = { {
    &rviz::Display::staticMetaObject,
    qt_meta_stringdata_moveit_rviz_plugin__RobotStateDisplay.data,
    qt_meta_data_moveit_rviz_plugin__RobotStateDisplay,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *moveit_rviz_plugin::RobotStateDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *moveit_rviz_plugin::RobotStateDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_moveit_rviz_plugin__RobotStateDisplay.stringdata0))
        return static_cast<void*>(this);
    return rviz::Display::qt_metacast(_clname);
}

int moveit_rviz_plugin::RobotStateDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = rviz::Display::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
