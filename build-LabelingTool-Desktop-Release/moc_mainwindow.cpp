/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../LabelingTool/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "NextImage"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 13), // "PreviousImage"
QT_MOC_LITERAL(4, 36, 9), // "SelectDir"
QT_MOC_LITERAL(5, 46, 3), // "dir"
QT_MOC_LITERAL(6, 50, 14), // "AssociateLabel"
QT_MOC_LITERAL(7, 65, 4), // "Undo"
QT_MOC_LITERAL(8, 70, 16), // "CreateNewProject"
QT_MOC_LITERAL(9, 87, 8), // "AddLabel"
QT_MOC_LITERAL(10, 96, 11), // "RemoveLabel"
QT_MOC_LITERAL(11, 108, 10), // "EditLabels"
QT_MOC_LITERAL(12, 119, 15), // "FinalizeProject"
QT_MOC_LITERAL(13, 135, 11), // "SaveProject"
QT_MOC_LITERAL(14, 147, 11), // "LoadProject"
QT_MOC_LITERAL(15, 159, 13), // "AddMultiLabel"
QT_MOC_LITERAL(16, 173, 16), // "RemoveMultiLabel"
QT_MOC_LITERAL(17, 190, 15), // "EditMultiLabels"
QT_MOC_LITERAL(18, 206, 19), // "AssociateMultiLabel"
QT_MOC_LITERAL(19, 226, 16), // "MultiSaveProject"
QT_MOC_LITERAL(20, 243, 20) // "MultiFinalizeProject"

    },
    "MainWindow\0NextImage\0\0PreviousImage\0"
    "SelectDir\0dir\0AssociateLabel\0Undo\0"
    "CreateNewProject\0AddLabel\0RemoveLabel\0"
    "EditLabels\0FinalizeProject\0SaveProject\0"
    "LoadProject\0AddMultiLabel\0RemoveMultiLabel\0"
    "EditMultiLabels\0AssociateMultiLabel\0"
    "MultiSaveProject\0MultiFinalizeProject"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a /* Public */,
       3,    0,  105,    2, 0x0a /* Public */,
       4,    1,  106,    2, 0x0a /* Public */,
       6,    0,  109,    2, 0x0a /* Public */,
       7,    0,  110,    2, 0x0a /* Public */,
       8,    0,  111,    2, 0x0a /* Public */,
       9,    0,  112,    2, 0x0a /* Public */,
      10,    0,  113,    2, 0x0a /* Public */,
      11,    0,  114,    2, 0x0a /* Public */,
      12,    0,  115,    2, 0x0a /* Public */,
      13,    0,  116,    2, 0x0a /* Public */,
      14,    1,  117,    2, 0x0a /* Public */,
      15,    0,  120,    2, 0x0a /* Public */,
      16,    0,  121,    2, 0x0a /* Public */,
      17,    0,  122,    2, 0x0a /* Public */,
      18,    1,  123,    2, 0x0a /* Public */,
      19,    0,  126,    2, 0x0a /* Public */,
      20,    0,  127,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NextImage(); break;
        case 1: _t->PreviousImage(); break;
        case 2: _t->SelectDir((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->AssociateLabel(); break;
        case 4: _t->Undo(); break;
        case 5: _t->CreateNewProject(); break;
        case 6: _t->AddLabel(); break;
        case 7: _t->RemoveLabel(); break;
        case 8: _t->EditLabels(); break;
        case 9: _t->FinalizeProject(); break;
        case 10: _t->SaveProject(); break;
        case 11: _t->LoadProject((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->AddMultiLabel(); break;
        case 13: _t->RemoveMultiLabel(); break;
        case 14: _t->EditMultiLabels(); break;
        case 15: _t->AssociateMultiLabel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->MultiSaveProject(); break;
        case 17: _t->MultiFinalizeProject(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
