/****************************************************************************
** Meta object code from reading C++ file 'ShowCategories.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/interface/ShowCategories.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ShowCategories.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ShowCategories_t {
    QByteArrayData data[19];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShowCategories_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShowCategories_t qt_meta_stringdata_ShowCategories = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ShowCategories"
QT_MOC_LITERAL(1, 15, 19), // "onCustomContextMenu"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "point"
QT_MOC_LITERAL(4, 42, 17), // "handleItemChanged"
QT_MOC_LITERAL(5, 60, 14), // "QStandardItem*"
QT_MOC_LITERAL(6, 75, 7), // "newItem"
QT_MOC_LITERAL(7, 83, 26), // "handleItemSelectionChanged"
QT_MOC_LITERAL(8, 110, 7), // "current"
QT_MOC_LITERAL(9, 118, 14), // "detectEmptyRow"
QT_MOC_LITERAL(10, 133, 16), // "addButtonClicked"
QT_MOC_LITERAL(11, 150, 19), // "removeButtonClicked"
QT_MOC_LITERAL(12, 170, 17), // "editButtonCLicked"
QT_MOC_LITERAL(13, 188, 11), // "addCategory"
QT_MOC_LITERAL(14, 200, 14), // "addSubcategory"
QT_MOC_LITERAL(15, 215, 14), // "removeCategory"
QT_MOC_LITERAL(16, 230, 17), // "removeSubcategory"
QT_MOC_LITERAL(17, 248, 14), // "updateCategory"
QT_MOC_LITERAL(18, 263, 17) // "updateSubcategory"

    },
    "ShowCategories\0onCustomContextMenu\0\0"
    "point\0handleItemChanged\0QStandardItem*\0"
    "newItem\0handleItemSelectionChanged\0"
    "current\0detectEmptyRow\0addButtonClicked\0"
    "removeButtonClicked\0editButtonCLicked\0"
    "addCategory\0addSubcategory\0removeCategory\0"
    "removeSubcategory\0updateCategory\0"
    "updateSubcategory"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShowCategories[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       4,    1,   82,    2, 0x08 /* Private */,
       7,    1,   85,    2, 0x08 /* Private */,
       9,    0,   88,    2, 0x08 /* Private */,
      10,    0,   89,    2, 0x08 /* Private */,
      11,    0,   90,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,
      15,    0,   94,    2, 0x08 /* Private */,
      16,    0,   95,    2, 0x08 /* Private */,
      17,    0,   96,    2, 0x08 /* Private */,
      18,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QModelIndex,    8,
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

void ShowCategories::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ShowCategories *_t = static_cast<ShowCategories *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onCustomContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->handleItemChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 2: _t->handleItemSelectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 3: _t->detectEmptyRow(); break;
        case 4: _t->addButtonClicked(); break;
        case 5: _t->removeButtonClicked(); break;
        case 6: _t->editButtonCLicked(); break;
        case 7: _t->addCategory(); break;
        case 8: _t->addSubcategory(); break;
        case 9: _t->removeCategory(); break;
        case 10: _t->removeSubcategory(); break;
        case 11: _t->updateCategory(); break;
        case 12: _t->updateSubcategory(); break;
        default: ;
        }
    }
}

const QMetaObject ShowCategories::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ShowCategories.data,
      qt_meta_data_ShowCategories,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ShowCategories::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShowCategories::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ShowCategories.stringdata0))
        return static_cast<void*>(const_cast< ShowCategories*>(this));
    return QWidget::qt_metacast(_clname);
}

int ShowCategories::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
