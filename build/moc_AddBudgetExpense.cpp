/****************************************************************************
** Meta object code from reading C++ file 'AddBudgetExpense.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/interface/AddBudgetExpense.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddBudgetExpense.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddBudgetExpense_t {
    QByteArrayData data[13];
    char stringdata0[241];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddBudgetExpense_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddBudgetExpense_t qt_meta_stringdata_AddBudgetExpense = {
    {
QT_MOC_LITERAL(0, 0, 16), // "AddBudgetExpense"
QT_MOC_LITERAL(1, 17, 32), // "handleBudgetTypeSelectionChanged"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 5), // "index"
QT_MOC_LITERAL(4, 57, 32), // "handleBankIssuerSelectionChanged"
QT_MOC_LITERAL(5, 90, 11), // "bank_issuer"
QT_MOC_LITERAL(6, 102, 28), // "handleNumberSelectionChanged"
QT_MOC_LITERAL(7, 131, 6), // "number"
QT_MOC_LITERAL(8, 138, 30), // "handleCategorySelectionChanged"
QT_MOC_LITERAL(9, 169, 8), // "category"
QT_MOC_LITERAL(10, 178, 33), // "handleSubCategorySelectionCha..."
QT_MOC_LITERAL(11, 212, 11), // "subCategory"
QT_MOC_LITERAL(12, 224, 16) // "addButtonClicked"

    },
    "AddBudgetExpense\0handleBudgetTypeSelectionChanged\0"
    "\0index\0handleBankIssuerSelectionChanged\0"
    "bank_issuer\0handleNumberSelectionChanged\0"
    "number\0handleCategorySelectionChanged\0"
    "category\0handleSubCategorySelectionChanged\0"
    "subCategory\0addButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddBudgetExpense[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       6,    1,   50,    2, 0x08 /* Private */,
       8,    1,   53,    2, 0x08 /* Private */,
      10,    1,   56,    2, 0x08 /* Private */,
      12,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

       0        // eod
};

void AddBudgetExpense::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddBudgetExpense *_t = static_cast<AddBudgetExpense *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleBudgetTypeSelectionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->handleBankIssuerSelectionChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->handleNumberSelectionChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->handleCategorySelectionChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->handleSubCategorySelectionChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->addButtonClicked(); break;
        default: ;
        }
    }
}

const QMetaObject AddBudgetExpense::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AddBudgetExpense.data,
      qt_meta_data_AddBudgetExpense,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddBudgetExpense::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddBudgetExpense::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddBudgetExpense.stringdata0))
        return static_cast<void*>(const_cast< AddBudgetExpense*>(this));
    return QWidget::qt_metacast(_clname);
}

int AddBudgetExpense::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
