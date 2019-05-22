/********************************************************************************
** Form generated from reading UI file 'labeleditor.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABELEDITOR_H
#define UI_LABELEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LabelEditor
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit0;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QDialog *LabelEditor)
    {
        if (LabelEditor->objectName().isEmpty())
            LabelEditor->setObjectName(QStringLiteral("LabelEditor"));
        LabelEditor->resize(537, 260);
        LabelEditor->setMaximumSize(QSize(16777215, 765));
        buttonBox = new QDialogButtonBox(LabelEditor);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(350, 210, 180, 40));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        lineEdit0 = new QLineEdit(LabelEditor);
        lineEdit0->setObjectName(QStringLiteral("lineEdit0"));
        lineEdit0->setGeometry(QRect(25, 25, 460, 40));
        lineEdit0->setMinimumSize(QSize(0, 40));
        lineEdit1 = new QLineEdit(LabelEditor);
        lineEdit1->setObjectName(QStringLiteral("lineEdit1"));
        lineEdit1->setGeometry(QRect(25, 85, 460, 40));
        lineEdit1->setMinimumSize(QSize(0, 40));
        lineEdit2 = new QLineEdit(LabelEditor);
        lineEdit2->setObjectName(QStringLiteral("lineEdit2"));
        lineEdit2->setGeometry(QRect(25, 145, 460, 40));
        lineEdit2->setMinimumSize(QSize(0, 40));
        scrollArea = new QScrollArea(LabelEditor);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 521, 191));
        scrollArea->setMaximumSize(QSize(16777215, 681));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 521, 191));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContents);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 481, 191));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);
        scrollArea->raise();
        buttonBox->raise();
        lineEdit0->raise();
        lineEdit1->raise();
        lineEdit2->raise();

        retranslateUi(LabelEditor);
        QObject::connect(buttonBox, SIGNAL(accepted()), LabelEditor, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LabelEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(LabelEditor);
    } // setupUi

    void retranslateUi(QDialog *LabelEditor)
    {
        LabelEditor->setWindowTitle(QApplication::translate("LabelEditor", "Label Editor", Q_NULLPTR));
        lineEdit0->setPlaceholderText(QApplication::translate("LabelEditor", "Insert Label 0 name", Q_NULLPTR));
        lineEdit1->setPlaceholderText(QApplication::translate("LabelEditor", "Insert Label 1 name", Q_NULLPTR));
        lineEdit2->setPlaceholderText(QApplication::translate("LabelEditor", "Insert Label 2 name", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LabelEditor: public Ui_LabelEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELEDITOR_H
