#pragma once

#include <QPushButton>
#include <QDeBUG>
#include <QPropertyAnimation>

class GameButton : public QPushButton
{
	Q_OBJECT

public:
	explicit GameButton(QObject *parent = Q_NULLPTR);
	GameButton(QString normalImg, QString pressImg = NULL);//重载

	void zoom1();
	void zoom2();

	void mousePressEvent(QMouseEvent* e);
	void mouseReleaseEvent(QMouseEvent* e);

	~GameButton();

private:

	QString normalImgPath;  //默认显示图片路径
	QString pressedImgPath; //按下后显示图片路径

};
