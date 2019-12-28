#include "ChooseLevelScene.h"

ChooseLevelScene::ChooseLevelScene(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->setWindowTitle(u8"Ñ¡Ôñ¹Ø¿¨ - ·­½ð±Ò");
	this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
	connect(ui.actionQuit, &QAction::triggered, [=]() {this->close(); });

	GameButton* backButton = new GameButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
	backButton->setParent(this);
	backButton->move(this->width() - backButton->width(), this->height() - backButton->height());

	connect(backButton, &QPushButton::clicked, [=]() {
		this->hide();
		emit this->chooseSceneBack();
	});

	for (size_t i = 0; i < 20; i++)
	{
		GameButton* passButton = new GameButton(":/res/LevelIcon.png");
		passButton->setParent(this);
		passButton->move(25 + (i % 4) * 70, 150 + (i / 4) * 70);
		
		QLabel* label = new QLabel();
		label->setParent(this);

		label->setText(QString::number(i + 1));
		label->move(25 + (i % 4) * 70, 150 + (i / 4) * 70);
		label->setFixedSize(passButton->width(),passButton->height());

		label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
		label->setAttribute(Qt::WA_TransparentForMouseEvents, true);

		connect(passButton, &QPushButton::clicked, [=]() {
		
			if (pScene == NULL)
			{
				this->hide();
				pScene = new GameScene(i + 1);
				pScene->setGeometry(this->geometry());
				pScene->show();
			}

			connect(pScene, &GameScene::chooseSceneBack, [=]() {

				this->setGeometry(pScene->geometry());
				this->show();
				delete pScene;
				pScene = nullptr;

				});

		});
	}

}

ChooseLevelScene::~ChooseLevelScene()
{
}

void ChooseLevelScene::paintEvent(QPaintEvent*)
{
	QPainter painter(this);

	QPixmap pixScene;
	pixScene.load(":/res/PlayLevelSceneBg.png");
	painter.drawPixmap(0, 0, this->width(), this->height(), pixScene);

	QPixmap pixTitle;
	pixTitle.load(":/res/Title.png");
	painter.drawPixmap((this->width() - pixTitle.width()) * 0.5, 30, pixTitle.width(), pixTitle.height(), pixTitle);

}
