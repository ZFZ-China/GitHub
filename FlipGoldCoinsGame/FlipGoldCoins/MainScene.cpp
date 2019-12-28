#include "MainScene.h"

MainScene::MainScene(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->setWindowTitle(u8"·­½ð±Ò");
	this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
	connect(ui.actionQuit, &QAction::triggered, [=]() {this->close(); });

	ChooseLevelScene* chooseLevelScene = new ChooseLevelScene();

	GameButton* startButton = new GameButton(":/res/MenuSceneStartButton.png");
	startButton->setParent(this);
	startButton->move(this->width() * 0.5 - startButton->width() * 0.5, this->height() * 0.7);

	connect(startButton, &QPushButton::clicked, [=]() {
		startButton->zoom1();
		startButton->zoom2();

		QTimer::singleShot(500, [=]() {
			this->hide();
			chooseLevelScene->setGeometry(this->geometry());
			chooseLevelScene->show();
		});

	});

	connect(chooseLevelScene, &ChooseLevelScene::chooseSceneBack, [=]() {
		this->setGeometry(chooseLevelScene->geometry());
		this->show();
	});


}

void MainScene::paintEvent(QPaintEvent*)
{
	QPainter painter(this);

	QPixmap pixScene;
	pixScene.load(":/res/PlayLevelSceneBg.png");
	painter.drawPixmap(0,0,this->width(),this->height(),pixScene);

	QPixmap pixTitle;
	pixTitle.load(":/res/Title.png");
	pixTitle = pixTitle.scaled(pixTitle.width() * 0.5, pixTitle.height() * 0.5);
	painter.drawPixmap(10, 30, pixTitle.width(), pixTitle.height(), pixTitle);

}
