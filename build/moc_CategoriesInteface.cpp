/****************************************************************************
** Meta object code from reading C++ file 'CategoriesInteface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/interface/CategoriesInteface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CategoriesInteface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CategoriesInteface_t {
    QByteArrayData data[21];
    char stringdata0[307];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CategoriesInteface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CategoriesInteface_t qt_meta_stringdata_CategoriesInteface = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CategoriesInteface"
QT_MOC_LITERAL(1, 19, 16), // "categoriesEdited"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 4), // "type"
QT_MOC_LITERAL(4, 42, 19), // "onCustomContextMenu"
QT_MOC_LITERAL(5, 62, 5), // "point"
QT_MOC_LITERAL(6, 68, 17), // "handleItemChanged"
QT_MOC_LITERAL(7, 86, 14), // "QStandardItem*"
QT_MOC_LITERAL(8, 101, 7), // "newItem"
QT_MOC_LITERAL(9, 109, 26), // "handleItemSelectionChanged"
QT_MOC_LITERAL(10, 136, 7), // "current"
QT_MOC_LITERAL(11, 144, 14), // "detectEmptyRow"
QT_MOC_LITERAL(12, 159, 16), // "addButtonClicked"
QT_MOC_LITERAL(13, 176, 19), // "removeButtonClicked"
QT_MOC_LITERAL(14, 196, 17), // "editButtonCLicked"
QT_MOC_LITERAL(15, 214, 11), // "addCategory"
QT_MOC_LITERAL(16, 226, 14), // "addSubcategory"
QT_MOC_LITERAL(17, 241, 14), // "removeCategory"
QT_MOC_LITERAL(18, 256, 17), // "removeSubcategory"
QT_MOC_LITERAL(19, 274, 14), // "updateCategory"
QT_MOC_LITERAL(20, 289, 17) // "updateSubcategory"

    },
    "CategoriesInteface\0categoriesEdited\0"
    "\0type\0onCustomContextMenu\0point\0"
    "handleItemChanged\0QStandardItem*\0"
    "newItem\0handleItemSelectionChanged\0"
    "current\0detectEmptyRow\0addButtonClicked\0"
    "removeButtonClicked\0editButtonCLicked\0"
    "addCategory\0addSubcategory\0removeCategory\0"
    "removeSubcategory\0updateCategory\0"
    "updateSubcategory"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CategoriesInteface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   87,    2, 0x08 /* Private */,
       6,    1,   90,    2, 0x08 /* Private */,
       9,    1,   93,    2, 0x08 /* Private */,
      11,    0,   96,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,
      17,    0,  102,    2, 0x08 /* Private */,
      18,    0,  103,    2, 0x08 /* Private */,
      19,    0,  104,    2, 0x08 /* Private */,
      20,    0,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QModelIndex,   10,
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

void CategoriesInteface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CategoriesInteface *_t = static_cast<CategoriesInteface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->categoriesEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->onCustomContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 2: _t->handleItemChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 3: _t->handleItemSelectionChanged((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 4: _t->detectEmptyRow(); break;
        case 5: _t->addButtonClicked(); break;
        case 6: _t->removeButtonClicked(); break;
        case 7: _t->editButtonCLicked(); break;
        case 8: _t->addCategory(); break;
        case 9: _t->addSubcategory(); break;
        case 10: _t->removeCategory(); break;
        case 11: _t->removeSubcategory(); break;
        case 12: _t->updateCategory(); break;
        case 13: _t->updateSubcategory(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CategoriesInteface::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CategoriesInteface::categoriesEdited)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject CategoriesInteface::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CategoriesInteface.data,
      qt_meta_data_CategoriesInteface,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CategoriesInteface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CategoriesInteface::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CategoriesInteface.stringdata0))
        return static_cast<void*>(const_cast< CategoriesInteface*>(this));
    return QWidget::qt_metacast(_clname);
}

int CategoriesInteface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void CategoriesInteface::categoriesEdited(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
