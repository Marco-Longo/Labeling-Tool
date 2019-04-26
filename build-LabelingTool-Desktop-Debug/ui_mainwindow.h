/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionNew_Project;
    QAction *actionLoad_Project;
    QAction *actionSave_Project;
    QAction *actionFinalize_Project;
    QWidget *centralWidget;
    QPushButton *b_label0;
    QPushButton *b_label1;
    QPushButton *b_label2;
    QPushButton *b_addlabel;
    QPushButton *b_undo;
    QMenuBar *menuBar;
    QMenu *menuMen;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1980, 1024);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QFont font;
        font.setPointSize(10);
        actionQuit->setFont(font);
        actionNew_Project = new QAction(MainWindow);
        actionNew_Project->setObjectName(QStringLiteral("actionNew_Project"));
        actionNew_Project->setFont(font);
        actionLoad_Project = new QAction(MainWindow);
        actionLoad_Project->setObjectName(QStringLiteral("actionLoad_Project"));
        actionLoad_Project->setFont(font);
        actionSave_Project = new QAction(MainWindow);
        actionSave_Project->setObjectName(QStringLiteral("actionSave_Project"));
        actionSave_Project->setFont(font);
        actionFinalize_Project = new QAction(MainWindow);
        actionFinalize_Project->setObjectName(QStringLiteral("actionFinalize_Project"));
        actionFinalize_Project->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        b_label0 = new QPushButton(centralWidget);
        b_label0->setObjectName(QStringLiteral("b_label0"));
        b_label0->setEnabled(false);
        b_label0->setGeometry(QRect(1120, 70, 190, 40));
        b_label0->setCheckable(false);
        b_label0->setAutoExclusive(false);
        b_label1 = new QPushButton(centralWidget);
        b_label1->setObjectName(QStringLiteral("b_label1"));
        b_label1->setEnabled(false);
        b_label1->setGeometry(QRect(1120, 130, 190, 40));
        b_label1->setCheckable(false);
        b_label1->setAutoExclusive(false);
        b_label2 = new QPushButton(centralWidget);
        b_label2->setObjectName(QStringLiteral("b_label2"));
        b_label2->setEnabled(false);
        b_label2->setGeometry(QRect(1120, 190, 190, 40));
        b_label2->setCheckable(false);
        b_label2->setAutoExclusive(false);
        b_addlabel = new QPushButton(centralWidget);
        b_addlabel->setObjectName(QStringLiteral("b_addlabel"));
        b_addlabel->setGeometry(QRect(1110, 780, 190, 40));
        b_undo = new QPushButton(centralWidget);
        b_undo->setObjectName(QStringLiteral("b_undo"));
        b_undo->setEnabled(false);
        b_undo->setGeometry(QRect(1110, 720, 190, 40));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1980, 21));
        menuBar->setFont(font);
        menuMen = new QMenu(menuBar);
        menuMen->setObjectName(QStringLiteral("menuMen"));
        QFont font1;
        font1.setPointSize(11);
        menuMen->setFont(font1);
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMen->menuAction());
        menuMen->addSeparator();
        menuMen->addAction(actionNew_Project);
        menuMen->addAction(actionLoad_Project);
        menuMen->addAction(actionSave_Project);
        menuMen->addAction(actionFinalize_Project);
        menuMen->addSeparator();
        menuMen->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "LabelingTool", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
        actionNew_Project->setText(QApplication::translate("MainWindow", "New Project...", Q_NULLPTR));
        actionLoad_Project->setText(QApplication::translate("MainWindow", "Load Project...", Q_NULLPTR));
        actionSave_Project->setText(QApplication::translate("MainWindow", "Save Project", Q_NULLPTR));
        actionFinalize_Project->setText(QApplication::translate("MainWindow", "Finalize Project", Q_NULLPTR));
        b_label0->setText(QApplication::translate("MainWindow", "Label 0", Q_NULLPTR));
        b_label1->setText(QApplication::translate("MainWindow", "Label 1", Q_NULLPTR));
        b_label2->setText(QApplication::translate("MainWindow", "Label 2", Q_NULLPTR));
        b_addlabel->setText(QApplication::translate("MainWindow", "Add Label", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        b_undo->setToolTip(QApplication::translate("MainWindow", "Reverts to previously selected label", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        b_undo->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
        menuMen->setTitle(QApplication::translate("MainWindow", "Men\303\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
