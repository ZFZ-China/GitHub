#include "GameButton.h"

GameButton::GameButton(QObject *parent)
{
}

GameButton::GameButton(QString normalImg, QString pressImg)
{
	this->normalImgPath = normalImg;
	this->pressedImgPath = pressImg;

	QPixmap pixMap;

	if (!pixMap.load(normalImgPath))
	{
		qDebug() << u8"normalImgPath ·������ʧ��!";
	}

	this->setFixedSize(pixMap.width(),pixMap.height());
	this->setStyleSheet("QPushButton{border:0px}");
	this->setIcon(pixMap);
	this->setIconSize(QSize(pixMap.width(),pixMap.height()));
}

void GameButton::zoom1()
{
	QPropertyAnimation* animation1 = new QPropertyAnimation(this, "geometry");

	animation1->setDuration(200);
	animation1->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
	animation1->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);

	animation1->start(QAbstractAnimation::DeleteWhenStopped);
}

void GameButton::zoom2()
{
	QPropertyAnimation* animation2 = new QPropertyAnimation(this, "geometry");

	animation2->setDuration(200);
	animation2->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
	animation2->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));
	animation2->setEasingCurve(QEasingCurve::OutBounce);

	animation2->start(QAbstractAnimation::DeleteWhenStopped);
}

void GameButton::mousePressEvent(QMouseEvent* e)
{
	QPixmap pixMap;

	if (pixMap.load(pressedImgPath) && pressedImgPath != NULL)
	{
		this->setFixedSize(pixMap.width(), pixMap.height());
		this->setStyleSheet("QPushButton{border:0px}");
		this->setIcon(pixMap);
		this->setIconSize(QSize(pixMap.width(), pixMap.height()));
	}
	else if (!pixMap.load(pressedImgPath) && pressedImgPath != NULL)
	{
		qDebug() << u8"mousePressEvent pressedImgPath ·����ΪNULL,������ʧ��!";
	}
	else if (pressedImgPath == NULL)
	{
		qDebug() << u8"mousePressEvent pressedImgPath ·��ΪNULL,���ܵ��µ��õ� pressedImgPath �İ�ť��ʾ�쳣.";
	}

	return QPushButton::mousePressEvent(e);
}

void GameButton::mouseReleaseEvent(QMouseEvent* e)
{
	QPixmap pixMap;

	if (pixMap.load(normalImgPath) && normalImgPath != NULL)
	{
		this->setFixedSize(pixMap.width(), pixMap.height());
		this->setStyleSheet("QPushButton{border:0px}");
		this->setIcon(pixMap);
		this->setIconSize(QSize(pixMap.width(), pixMap.height()));
	}
	else if (normalImgPath == NULL)
	{
		qDebug() << u8"mouseReleaseEvent normalImgPath ·������ʧ��!";
	}

	return QPushButton::mouseReleaseEvent(e);
}

GameButton::~GameButton()
{
}
