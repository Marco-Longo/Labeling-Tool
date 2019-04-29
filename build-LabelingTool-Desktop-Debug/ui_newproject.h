/********************************************************************************
** Form generated from reading UI file 'newproject.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROJECT_H
#define UI_NEWPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NewProject
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *txtbox_name;
    QLineEdit *txtbox_dir;
    QPushButton *b_browse;

    void setupUi(QDialog *NewProject)
    {
        if (NewProject->objectName().isEmpty())
            NewProject->setObjectName(QStringLiteral("NewProject"));
        NewProject->resize(600, 200);
        buttonBox = new QDialogButtonBox(NewProject);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(380, 150, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        txtbox_name = new QLineEdit(NewProject);
        txtbox_name->setObjectName(QStringLiteral("txtbox_name"));
        txtbox_name->setGeometry(QRect(40, 20, 521, 31));
        txtbox_dir = new QLineEdit(NewProject);
        txtbox_dir->setObjectName(QStringLiteral("txtbox_dir"));
        txtbox_dir->setGeometry(QRect(40, 80, 521, 31));
        txtbox_dir->setReadOnly(true);
        b_browse = new QPushButton(NewProject);
        b_browse->setObjectName(QStringLiteral("b_browse"));
        b_browse->setGeometry(QRect(470, 120, 89, 25));

        retranslateUi(NewProject);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewProject, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewProject, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewProject);
    } // setupUi

    void retranslateUi(QDialog *NewProject)
    {
        NewProject->setWindowTitle(QApplication::translate("NewProject", "Create New Project", Q_NULLPTR));
        txtbox_name->setPlaceholderText(QApplication::translate("NewProject", "Insert project name", Q_NULLPTR));
        txtbox_dir->setPlaceholderText(QApplication::translate("NewProject", "Browse the directory you want to save your project in", Q_NULLPTR));
        b_browse->setText(QApplication::translate("NewProject", "Browse...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewProject: public Ui_NewProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECT_H
