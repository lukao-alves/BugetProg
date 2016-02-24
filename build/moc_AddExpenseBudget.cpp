/****************************************************************************
** Meta object code from reading C++ file 'AddExpenseBudget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/interface/AddExpenseBudget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddExpenseBudget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddExpenseBudget_t {
    QByteArrayData data[14];
    char stringdata0[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddExpenseBudget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddExpenseBudget_t qt_meta_stringdata_AddExpenseBudget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "AddExpenseBudget"
QT_MOC_LITERAL(1, 17, 5), // "crash"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 32), // "handleBudgetTypeSelectionChanged"
QT_MOC_LITERAL(4, 57, 5), // "index"
QT_MOC_LITERAL(5, 63, 32), // "handleBankIssuerSelectionChanged"
QT_MOC_LITERAL(6, 96, 11), // "bank_issuer"
QT_MOC_LITERAL(7, 108, 28), // "handleNumberSelectionChanged"
QT_MOC_LITERAL(8, 137, 6), // "number"
QT_MOC_LITERAL(9, 144, 30), // "handleCategorySelectionChanged"
QT_MOC_LITERAL(10, 175, 8), // "category"
QT_MOC_LITERAL(11, 184, 33), // "handleSubcategorySelectionCha..."
QT_MOC_LITERAL(12, 218, 11), // "subcategory"
QT_MOC_LITERAL(13, 230, 16) // "addButtonClicked"

    },
    "AddExpenseBudget\0crash\0\0"
    "handleBudgetTypeSelectionChanged\0index\0"
    "handleBankIssuerSelectionChanged\0"
    "bank_issuer\0handleNumberSelectionChanged\0"
    "number\0handleCategorySelectionChanged\0"
    "category\0handleSubcategorySelectionChanged\0"
    "subcategory\0addButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddExpenseBudget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   50,    2, 0x08 /* Private */,
       5,    1,   53,    2, 0x08 /* Private */,
       7,    1,   56,    2, 0x08 /* Private */,
       9,    1,   59,    2, 0x08 /* Private */,
      11,    1,   62,    2, 0x08 /* Private */,
      13,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,

       0        // eod
};

void AddExpenseBudget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddExpenseBudget *_t = static_cast<AddExpenseBudget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->crash(); break;
        case 1: _t->handleBudgetTypeSelectionChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->handleBankIssuerSelectionChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->handleNumberSelectionChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->handleCategorySelectionChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->handleSubcategorySelectionChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->addButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AddExpenseBudget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddExpenseBudget::crash)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject AddExpenseBudget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AddExpenseBudget.data,
      qt_meta_data_AddExpenseBudget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddExpenseBudget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddExpenseBudget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddExpenseBudget.stringdata0))
        return static_cast<void*>(const_cast< AddExpenseBudget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AddExpenseBudget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void AddExpenseBudget::crash()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
