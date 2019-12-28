#pragma once

#include <QMainWindow>
#include <QPainter>
#include <QLabel>
#include "ui_ChooseLevelScene.h"

#include "GameButton.h"
#include "GameScene.h"

class ChooseLevelScene : public QMainWindow
{
	Q_OBJECT

public:
	ChooseLevelScene(QWidget *parent = Q_NULLPTR);
	~ChooseLevelScene();

	void paintEvent(QPaintEvent*);

private:

	Ui::ChooseLevelScene ui;
	GameScene* pScene = NULL;

signals:

	void chooseSceneBack();

};
