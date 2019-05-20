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
#include <QtWidgets/QGroupBox>
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
    QGroupBox *jobGroup;
    QPushButton *b_singleLabel;
    QPushButton *b_multiLabel;
    QPushButton *b_segmentation;

    void setupUi(QDialog *NewProject)
    {
        if (NewProject->objectName().isEmpty())
            NewProject->setObjectName(QStringLiteral("NewProject"));
        NewProject->resize(600, 261);
        buttonBox = new QDialogButtonBox(NewProject);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(380, 210, 220, 40));
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
        jobGroup = new QGroupBox(NewProject);
        jobGroup->setObjectName(QStringLiteral("jobGroup"));
        jobGroup->setGeometry(QRect(40, 140, 521, 61));
        QFont font;
        font.setKerning(true);
        jobGroup->setFont(font);
        jobGroup->setCursor(QCursor(Qt::PointingHandCursor));
        jobGroup->setAutoFillBackground(false);
        jobGroup->setFlat(false);
        b_singleLabel = new QPushButton(jobGroup);
        b_singleLabel->setObjectName(QStringLiteral("b_singleLabel"));
        b_singleLabel->setGeometry(QRect(0, 20, 151, 41));
        b_singleLabel->setCheckable(true);
        b_singleLabel->setAutoExclusive(true);
        b_multiLabel = new QPushButton(jobGroup);
        b_multiLabel->setObjectName(QStringLiteral("b_multiLabel"));
        b_multiLabel->setGeometry(QRect(190, 20, 151, 41));
        b_multiLabel->setCheckable(true);
        b_multiLabel->setAutoExclusive(true);
        b_segmentation = new QPushButton(jobGroup);
        b_segmentation->setObjectName(QStringLiteral("b_segmentation"));
        b_segmentation->setGeometry(QRect(380, 20, 141, 41));
        b_segmentation->setCheckable(true);
        b_segmentation->setAutoExclusive(true);

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
        jobGroup->setTitle(QApplication::translate("NewProject", "Job", Q_NULLPTR));
        b_singleLabel->setText(QApplication::translate("NewProject", "Single Labeling", Q_NULLPTR));
        b_multiLabel->setText(QApplication::translate("NewProject", "Multi Labeling", Q_NULLPTR));
        b_segmentation->setText(QApplication::translate("NewProject", "Segmentation", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewProject: public Ui_NewProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECT_H
