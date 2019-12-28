#pragma once

#include <QPushButton>
#include <QDeBUG>
#include <QTimer>
#include <QPainter>

class GoldCoin : public QPushButton
{
	Q_OBJECT

public:
	GoldCoin(QObject *parent);
	GoldCoin(QString CoinImage);

	void changeFlag();
	void mousePressEvent(QMouseEvent* e);

	~GoldCoin();

	int posX;
	int posY;
	bool flag;
	bool isWin = false;

private:

	QTimer* timer1;
	QTimer* timer2;
	int min = 1;
	int max = 8;

	bool isAnimation = false;

signals:

	void reverseCompleteness();
};
