#include "GameScene.h"

GameScene::GameScene(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

GameScene::GameScene(int index)
{
	this->levalIndex = index;

	this->setFixedSize(320,588);
	this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
	this->setWindowTitle(u8"游戏进行 - 翻金币");

	QMenuBar* bar = this->menuBar();
	this->setMenuBar(bar);

	QMenu* startMenu = bar->addMenu(u8"开始");
	QAction* actionQuit = startMenu->addAction(u8"退出");
	connect(actionQuit, &QAction::triggered, [=]() {this->close(); });

	GameButton* backButton = new GameButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
	backButton->setParent(this);
	backButton->move(this->width() - backButton->width(), this->height() - backButton->height());

	connect(backButton, &QPushButton::clicked, [=]() {
		this->hide();
		emit this->chooseSceneBack();
	});


	QLabel* label = new QLabel;
	label->setParent(this);

	QFont font;
	font.setFamily(u8"微软雅黑");
	font.setPointSize(15);
	label->setFont(font);

	label->setText(QString(u8"Leavel: %1").arg(this->levalIndex));
	label->setGeometry(QRect(30, this->height() - 50, 120, 50));


	QLabel* winnerLabel = new QLabel;
	winnerLabel->setParent(this);

	QPropertyAnimation* winAnimation = new QPropertyAnimation(winnerLabel, "geometry");

	QPixmap winnerPixMap;
	if (winnerPixMap.load(":/res/LevelCompletedDialogBg.png"))
	{
		winnerLabel->setPixmap(winnerPixMap);
		winnerLabel->setGeometry(0, 0, winnerPixMap.width(), winnerPixMap.height());
		winnerLabel->move((this->width() - winnerPixMap.width()) * 0.5, -winnerPixMap.height());

		winAnimation->setDuration(1000);
		winAnimation->setStartValue(QRect(winnerLabel->x(), winnerLabel->y(), winnerLabel->width(), winnerLabel->height()));
		winAnimation->setEndValue(QRect(winnerLabel->x(), winnerLabel->y() + 180, winnerLabel->width(), winnerLabel->height()));
		winAnimation->setEasingCurve(QEasingCurve::OutBounce);
	}


	//--- GameCoreGraphics --- Start

	DataConfig cfg;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->levalCoinIndexArr[i][j] = cfg.mData[this->levalIndex][i][j];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			QLabel* label = new QLabel;
			label->setParent(this);

			label->setGeometry(0, 0, 50, 50);
			label->setPixmap(QPixmap(":/res/BoardNode.png"));

			label->move(57 + i * 50, 200 + j * 50);


			QString coinImgFName;
			if (levalCoinIndexArr[i][j] == 1)
			{
				coinImgFName = ":/res/Coin0001.png";
			}
			else
			{
				coinImgFName = ":/res/Coin0008.png";
			}

			GoldCoin* coin = new GoldCoin(coinImgFName);
			coin->setParent(this);
			coin->move(59 + i * 50, 204 + j * 50);
			coin->posX = i;
			coin->posY = j;
			coin->flag = levalCoinIndexArr[i][j];

			this->GameSceneCoinArr[i][j] = coin;
			connect(coin, &GoldCoin::clicked, [=]() {

				coin->changeFlag();
				levalCoinIndexArr[i][j] = levalCoinIndexArr[i][j] == 0 ? 1 : 0;

				QTimer::singleShot(180, this, [=]() {

					if (coin->posX + 1 <= 3)
					{
						GameSceneCoinArr[coin->posX + 1][coin->posY]->changeFlag();
						levalCoinIndexArr[coin->posX + 1][coin->posY] = levalCoinIndexArr[coin->posX + 1][coin->posY] == 0 ? 1 : 0;
					}
					if (coin->posX - 1 >= 0)
					{
						GameSceneCoinArr[coin->posX - 1][coin->posY]->changeFlag();
						levalCoinIndexArr[coin->posX - 1][coin->posY] = levalCoinIndexArr[coin->posX - 1][coin->posY] == 0 ? 1 : 0;
					}
					if (coin->posY + 1 <= 3)
					{
						GameSceneCoinArr[coin->posX][coin->posY + 1]->changeFlag();
						levalCoinIndexArr[coin->posX][coin->posY + 1] = levalCoinIndexArr[coin->posX + 1][coin->posY] == 0 ? 1 : 0;
					}
					if (coin->posY - 1 >= 0)
					{
						GameSceneCoinArr[coin->posX][coin->posY - 1]->changeFlag();
						levalCoinIndexArr[coin->posX][coin->posY - 1] = levalCoinIndexArr[coin->posX + 1][coin->posY] == 0 ? 1 : 0;
					}

					emit coin->reverseCompleteness();
				});

			});

			connect(coin, &GoldCoin::reverseCompleteness, [=]() {

				this->isWinCondition = true;
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (GameSceneCoinArr[i][j]->flag == false)
						{
							this->isWinCondition = false;
							break;
						}
					}
				}

				if (this->isWinCondition == true)
				{
					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							GameSceneCoinArr[i][j]->isWin = true;
						}
					}
					winAnimation->start(QAbstractAnimation::DeleteWhenStopped);
				}

			});
		}
	}

	//--- GameCoreGraphics --- End

}

GameScene::~GameScene()
{
}

void GameScene::paintEvent(QPaintEvent*)
{
	QPainter painter(this);

	QPixmap pixScene;
	pixScene.load(":/res/PlayLevelSceneBg.png");
	painter.drawPixmap(0, 0, this->width(), this->height(), pixScene);

	QPixmap pixTitle;
	pixTitle.load(":/res/Title.png");
	pixTitle = pixTitle.scaled(pixTitle.width() * 0.5, pixTitle.height() * 0.5);
	painter.drawPixmap(10, 30, pixTitle.width(), pixTitle.height(), pixTitle);

}
