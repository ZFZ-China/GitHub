#pragma once

#include <QPushButton>
#include <QDeBUG>
#include <QPropertyAnimation>

class GameButton : public QPushButton
{
	Q_OBJECT

public:
	explicit GameButton(QObject *parent = Q_NULLPTR);
	GameButton(QString normalImg, QString pressImg = NULL);//����

	void zoom1();
	void zoom2();

	void mousePressEvent(QMouseEvent* e);
	void mouseReleaseEvent(QMouseEvent* e);

	~GameButton();

private:

	QString normalImgPath;  //Ĭ����ʾͼƬ·��
	QString pressedImgPath; //���º���ʾͼƬ·��

};
