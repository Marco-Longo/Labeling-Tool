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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
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
    QPushButton *b_removelabel;
    QToolButton *b_editlabels;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QMenuBar *menuBar;
    QMenu *menuMen;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1980, 1024);
        MainWindow->setToolButtonStyle(Qt::ToolButtonFollowStyle);
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
        actionSave_Project->setEnabled(false);
        actionSave_Project->setFont(font);
        actionFinalize_Project = new QAction(MainWindow);
        actionFinalize_Project->setObjectName(QStringLiteral("actionFinalize_Project"));
        actionFinalize_Project->setEnabled(false);
        actionFinalize_Project->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        b_label0 = new QPushButton(centralWidget);
        b_label0->setObjectName(QStringLiteral("b_label0"));
        b_label0->setEnabled(false);
        b_label0->setGeometry(QRect(1120, 60, 190, 40));
        b_label0->setMinimumSize(QSize(0, 40));
        b_label0->setMaximumSize(QSize(190, 16777215));
        b_label0->setCheckable(false);
        b_label0->setAutoExclusive(false);
        b_label1 = new QPushButton(centralWidget);
        b_label1->setObjectName(QStringLiteral("b_label1"));
        b_label1->setEnabled(false);
        b_label1->setGeometry(QRect(1120, 120, 190, 40));
        b_label1->setMinimumSize(QSize(0, 40));
        b_label1->setMaximumSize(QSize(190, 16777215));
        b_label1->setCheckable(false);
        b_label1->setAutoExclusive(false);
        b_label2 = new QPushButton(centralWidget);
        b_label2->setObjectName(QStringLiteral("b_label2"));
        b_label2->setEnabled(false);
        b_label2->setGeometry(QRect(1120, 180, 190, 40));
        b_label2->setMinimumSize(QSize(0, 40));
        b_label2->setMaximumSize(QSize(190, 16777215));
        b_label2->setCheckable(false);
        b_label2->setAutoExclusive(false);
        b_addlabel = new QPushButton(centralWidget);
        b_addlabel->setObjectName(QStringLiteral("b_addlabel"));
        b_addlabel->setEnabled(false);
        b_addlabel->setGeometry(QRect(1120, 780, 90, 40));
        b_undo = new QPushButton(centralWidget);
        b_undo->setObjectName(QStringLiteral("b_undo"));
        b_undo->setEnabled(false);
        b_undo->setGeometry(QRect(1120, 720, 190, 40));
        b_removelabel = new QPushButton(centralWidget);
        b_removelabel->setObjectName(QStringLiteral("b_removelabel"));
        b_removelabel->setEnabled(false);
        b_removelabel->setGeometry(QRect(1220, 780, 90, 40));
        b_editlabels = new QToolButton(centralWidget);
        b_editlabels->setObjectName(QStringLiteral("b_editlabels"));
        b_editlabels->setGeometry(QRect(1340, 70, 21, 21));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(1120, 60, 211, 651));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 211, 651));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContents);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 191, 651));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(20);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);
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
#ifndef QT_NO_SHORTCUT
        actionNew_Project->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionLoad_Project->setText(QApplication::translate("MainWindow", "Load Project...", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionLoad_Project->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave_Project->setText(QApplication::translate("MainWindow", "Save Project", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSave_Project->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionFinalize_Project->setText(QApplication::translate("MainWindow", "Finalize Project", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionFinalize_Project->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        b_label0->setText(QApplication::translate("MainWindow", "Label 0", Q_NULLPTR));
        b_label1->setText(QApplication::translate("MainWindow", "Label 1", Q_NULLPTR));
        b_label2->setText(QApplication::translate("MainWindow", "Label 2", Q_NULLPTR));
        b_addlabel->setText(QApplication::translate("MainWindow", "   Label", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        b_undo->setToolTip(QApplication::translate("MainWindow", "Reverts to previously selected label", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        b_undo->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
        b_removelabel->setText(QApplication::translate("MainWindow", "   Label", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        b_editlabels->setToolTip(QApplication::translate("MainWindow", "Edit labels", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        b_editlabels->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        menuMen->setTitle(QApplication::translate("MainWindow", "Men\303\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
