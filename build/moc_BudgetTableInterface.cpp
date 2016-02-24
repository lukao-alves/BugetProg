/****************************************************************************
** Meta object code from reading C++ file 'BudgetTableInterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/interface/BudgetTableInterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BudgetTableInterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BudgetTableInterface_t {
    QByteArrayData data[13];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BudgetTableInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BudgetTableInterface_t qt_meta_stringdata_BudgetTableInterface = {
    {
QT_MOC_LITERAL(0, 0, 20), // "BudgetTableInterface"
QT_MOC_LITERAL(1, 21, 18), // "showEditCategories"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 26), // "handleCategoriesCustomMenu"
QT_MOC_LITERAL(4, 68, 5), // "point"
QT_MOC_LITERAL(5, 74, 22), // "handleBudgetCustomMenu"
QT_MOC_LITERAL(6, 97, 12), // "updateTables"
QT_MOC_LITERAL(7, 110, 4), // "type"
QT_MOC_LITERAL(8, 115, 20), // "updateWidgetGeometry"
QT_MOC_LITERAL(9, 136, 9), // "addBudget"
QT_MOC_LITERAL(10, 146, 10), // "editBudget"
QT_MOC_LITERAL(11, 157, 12), // "removeBudget"
QT_MOC_LITERAL(12, 170, 10) // "viewBudget"

    },
    "BudgetTableInterface\0showEditCategories\0"
    "\0handleCategoriesCustomMenu\0point\0"
    "handleBudgetCustomMenu\0updateTables\0"
    "type\0updateWidgetGeometry\0addBudget\0"
    "editBudget\0removeBudget\0viewBudget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BudgetTableInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    1,   60,    2, 0x08 /* Private */,
       5,    1,   63,    2, 0x08 /* Private */,
       6,    1,   66,    2, 0x08 /* Private */,
       8,    0,   69,    2, 0x08 /* Private */,
       9,    0,   70,    2, 0x08 /* Private */,
      10,    0,   71,    2, 0x08 /* Private */,
      11,    0,   72,    2, 0x08 /* Private */,
      12,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,    4,
    QMetaType::Void, QMetaType::QPoint,    4,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BudgetTableInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BudgetTableInterface *_t = static_cast<BudgetTableInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showEditCategories(); break;
        case 1: _t->handleCategoriesCustomMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 2: _t->handleBudgetCustomMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 3: _t->updateTables((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->updateWidgetGeometry(); break;
        case 5: _t->addBudget(); break;
        case 6: _t->editBudget(); break;
        case 7: _t->removeBudget(); break;
        case 8: _t->viewBudget(); break;
        default: ;
        }
    }
}

const QMetaObject BudgetTableInterface::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BudgetTableInterface.data,
      qt_meta_data_BudgetTableInterface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BudgetTableInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BudgetTableInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BudgetTableInterface.stringdata0))
        return static_cast<void*>(const_cast< BudgetTableInterface*>(this));
    return QWidget::qt_metacast(_clname);
}

int BudgetTableInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
