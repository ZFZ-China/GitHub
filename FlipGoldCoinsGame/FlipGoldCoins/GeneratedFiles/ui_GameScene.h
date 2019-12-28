/********************************************************************************
** Form generated from reading UI file 'GameScene.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESCENE_H
#define UI_GAMESCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameScene
{
public:
    QWidget *centralWidget;

    void setupUi(QMainWindow *GameScene)
    {
        if (GameScene->objectName().isEmpty())
            GameScene->setObjectName(QString::fromUtf8("GameScene"));
        GameScene->resize(320, 588);
        GameScene->setMinimumSize(QSize(320, 588));
        GameScene->setMaximumSize(QSize(320, 588));
        centralWidget = new QWidget(GameScene);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GameScene->setCentralWidget(centralWidget);

        retranslateUi(GameScene);

        QMetaObject::connectSlotsByName(GameScene);
    } // setupUi

    void retranslateUi(QMainWindow *GameScene)
    {
        GameScene->setWindowTitle(QApplication::translate("GameScene", "GameScene", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameScene: public Ui_GameScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESCENE_H
