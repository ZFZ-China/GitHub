#pragma once

#include <QMainWindow>
#include <QPainter>
#include <QMenuBar>
#include <QLabel>
#include <QTimer>

#include "ui_GameScene.h"
#include "GameButton.h"
#include "GoldCoin.h"
#include "DataConfig.h"

class GameScene : public QMainWindow
{
	Q_OBJECT

public:
	GameScene(QWidget *parent = Q_NULLPTR);
	GameScene(int index);
	~GameScene();

	void paintEvent(QPaintEvent*);

private:

	Ui::GameScene ui;
	int levalIndex;
	int levalCoinIndexArr[4][4];

	GoldCoin* GameSceneCoinArr[4][4];

	bool isWinCondition = true;

signals:

	void chooseSceneBack();

};
