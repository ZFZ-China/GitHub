#include "GoldCoin.h"

GoldCoin::GoldCoin(QObject *parent)
{

}

GoldCoin::GoldCoin(QString CoinImage)
{
	QPixmap pixMap;
	if (!pixMap.load(CoinImage))
	{
		qDebug() << u8"GoldCoin(QString CoinImage) 参数错误,无法获取图像!";
	}

	this->setFixedSize(pixMap.width(), pixMap.height());
	this->setStyleSheet("QPushButton{border:0px}");
	this->setIcon(pixMap);
	this->setIconSize(QSize(pixMap.width(), pixMap.height()));

	this->timer1 = new QTimer(this);
	this->timer2 = new QTimer(this);

	connect(timer1, &QTimer::timeout, [=]() {

		QPixmap pixMap;
		pixMap.load(QString(u8":/res/Coin000%1.png").arg((this->min)++));
		
		this->setFixedSize(pixMap.width(),pixMap.height());
		this->setStyleSheet("QPushButton{border:0px;}");

		this->setIcon(pixMap);
		this->setIconSize(QSize(pixMap.width(),pixMap.height()));

		if (this->min > this->max) 
		{
			this->min = 1;
			this->isAnimation = false;
			this->timer1->stop();
		}
	});

	connect(timer2, &QTimer::timeout, [=]() {

		QPixmap pixMap;
		pixMap.load(QString(u8":/res/Coin000%1.png").arg((this->max)--));

		this->setFixedSize(pixMap.width(), pixMap.height());
		this->setStyleSheet("QPushButton{border:0px;}");

		this->setIcon(pixMap);
		this->setIconSize(QSize(pixMap.width(), pixMap.height()));

		if (this->max < this->min)
		{
			this->max = 8;
			this->isAnimation = false;
			this->timer2->stop();
		}
	});



}

GoldCoin::~GoldCoin()
{
}

void GoldCoin::changeFlag()
{
	if (this->flag)
	{
		this->timer1->start(30);
		this->isAnimation = true;
		this->flag = false;
	}
	else
	{
		this->timer2->start(30);
		this->isAnimation = true;
		this->flag = true;
	}
}

void GoldCoin::mousePressEvent(QMouseEvent* e)
{
	if (this->isAnimation || this->isWin == true)
	{
		return;
	}
	else
	{
		return QPushButton::mousePressEvent(e);
	}

}