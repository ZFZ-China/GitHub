#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainScene.h"
#include <QPainter>
#include <QTimer>

#include "GameButton.h"
#include "ChooseLevelScene.h"

class MainScene : public QMainWindow
{
	Q_OBJECT

public:
	MainScene(QWidget *parent = Q_NULLPTR);

	void paintEvent(QPaintEvent*);

private:
	Ui::MainSceneClass ui;
};
