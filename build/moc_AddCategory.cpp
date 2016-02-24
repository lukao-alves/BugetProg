/****************************************************************************
** Meta object code from reading C++ file 'AddCategory.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/interface/AddCategory.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AddCategory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AddCategory_t {
    QByteArrayData data[10];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddCategory_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddCategory_t qt_meta_stringdata_AddCategory = {
    {
QT_MOC_LITERAL(0, 0, 11), // "AddCategory"
QT_MOC_LITERAL(1, 12, 13), // "categoryAdded"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "category"
QT_MOC_LITERAL(4, 36, 16), // "subcategoryAdded"
QT_MOC_LITERAL(5, 53, 11), // "subcategory"
QT_MOC_LITERAL(6, 65, 26), // "handleTypeSelectionChanced"
QT_MOC_LITERAL(7, 92, 4), // "type"
QT_MOC_LITERAL(8, 97, 21), // "handleCategoryEditing"
QT_MOC_LITERAL(9, 119, 6) // "accept"

    },
    "AddCategory\0categoryAdded\0\0category\0"
    "subcategoryAdded\0subcategory\0"
    "handleTypeSelectionChanced\0type\0"
    "handleCategoryEditing\0accept"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddCategory[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   45,    2, 0x08 /* Private */,
       8,    0,   48,    2, 0x08 /* Private */,
       9,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AddCategory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AddCategory *_t = static_cast<AddCategory *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->categoryAdded((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->subcategoryAdded((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->handleTypeSelectionChanced((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->handleCategoryEditing(); break;
        case 4: _t->accept(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AddCategory::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddCategory::categoryAdded)) {
                *result = 0;
            }
        }
        {
            typedef void (AddCategory::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AddCategory::subcategoryAdded)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject AddCategory::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AddCategory.data,
      qt_meta_data_AddCategory,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddCategory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddCategory::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddCategory.stringdata0))
        return static_cast<void*>(const_cast< AddCategory*>(this));
    return QDialog::qt_metacast(_clname);
}

int AddCategory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void AddCategory::categoryAdded(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AddCategory::subcategoryAdded(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
