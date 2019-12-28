/********************************************************************************
** Form generated from reading UI file 'MainScene.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainSceneClass
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *MainSceneClass)
    {
        if (MainSceneClass->objectName().isEmpty())
            MainSceneClass->setObjectName(QString::fromUtf8("MainSceneClass"));
        MainSceneClass->resize(320, 588);
        MainSceneClass->setMinimumSize(QSize(320, 588));
        MainSceneClass->setMaximumSize(QSize(320, 588));
        actionQuit = new QAction(MainSceneClass);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(MainSceneClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainSceneClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainSceneClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 320, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainSceneClass->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionQuit);

        retranslateUi(MainSceneClass);

        QMetaObject::connectSlotsByName(MainSceneClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainSceneClass)
    {
        MainSceneClass->setWindowTitle(QApplication::translate("MainSceneClass", "MainScene", nullptr));
        actionQuit->setText(QApplication::translate("MainSceneClass", "\351\200\200\345\207\272", nullptr));
        menu->setTitle(QApplication::translate("MainSceneClass", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainSceneClass: public Ui_MainSceneClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H
