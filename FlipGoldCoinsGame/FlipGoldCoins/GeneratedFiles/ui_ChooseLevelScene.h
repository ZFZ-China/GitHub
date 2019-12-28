/********************************************************************************
** Form generated from reading UI file 'ChooseLevelScene.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSELEVELSCENE_H
#define UI_CHOOSELEVELSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseLevelScene
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *ChooseLevelScene)
    {
        if (ChooseLevelScene->objectName().isEmpty())
            ChooseLevelScene->setObjectName(QString::fromUtf8("ChooseLevelScene"));
        ChooseLevelScene->resize(320, 588);
        ChooseLevelScene->setMinimumSize(QSize(320, 588));
        ChooseLevelScene->setMaximumSize(QSize(320, 588));
        actionQuit = new QAction(ChooseLevelScene);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(ChooseLevelScene);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ChooseLevelScene->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ChooseLevelScene);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 320, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        ChooseLevelScene->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionQuit);

        retranslateUi(ChooseLevelScene);

        QMetaObject::connectSlotsByName(ChooseLevelScene);
    } // setupUi

    void retranslateUi(QMainWindow *ChooseLevelScene)
    {
        ChooseLevelScene->setWindowTitle(QApplication::translate("ChooseLevelScene", "ChooseLevelScene", nullptr));
        actionQuit->setText(QApplication::translate("ChooseLevelScene", "\351\200\200\345\207\272", nullptr));
        menu->setTitle(QApplication::translate("ChooseLevelScene", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChooseLevelScene: public Ui_ChooseLevelScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSELEVELSCENE_H
