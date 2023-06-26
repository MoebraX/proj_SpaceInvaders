#include "mainmenu.h"
#include "button.h"
#include "game.h"

Mainmenu::Mainmenu()
{
     //create secene
    mainmenu_scene = new QGraphicsScene();
    mainmenu_scene->setSceneRect(0, 0, 800, 600);// make the secen 600*700 instead of infinity by infinity
    mainmenu_scene->setBackgroundBrush(Qt::blue);

    //make the newly created scene the scene to visualize
    //it ccan be used to visualize scene
    setScene(mainmenu_scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    // Center the game window on the screen
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();
    int windowX = (screenWidth - width()) / 2;
    int windowY = (screenHeight - height()) / 2;
    setGeometry(windowX, windowY, width(), height());

    //Title of the game
    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("Space Invaders"));
    QFontDatabase::addApplicationFont(":/fonts/MyGirlIsRetro-0Grz.ttf");
    QFont titleFont(":/fonts/MyGirlIsRetro-0Grz.ttf", 50);
    titleText->setFont(titleFont);
    titleText->setDefaultTextColor(Qt::yellow);
    int xTitlePos = this->width()/2 - titleText->boundingRect().width()/2;
    int yTitlePos = 150;
    titleText->setPos(xTitlePos, yTitlePos);
    mainmenu_scene->addItem(titleText);

    // create play button
    Button *playButton = new Button(QString("Play"));
    int xPlayPos = this->width()/2 - playButton->boundingRect().width()/2;
    int yPlayPos = 275;
    playButton->setPos(xPlayPos, yPlayPos);
    connect(playButton, SIGNAL(clicked()), this, SLOT(start()));
    mainmenu_scene->addItem(playButton);

    // create settings button
    Button *settingsButton = new Button(QString("Settings"));
    int xSettingsPos = this->width()/2 - settingsButton->boundingRect().width()/2;
    int ySettingsPos = 350;
    settingsButton->setPos(xSettingsPos, ySettingsPos);
    //connect(settingsButton, SIGNAL(clicked()), this, SLOT(displaySettingsMenu()));
    mainmenu_scene->addItem(settingsButton);

    // create quit button
    Button *quitButton = new Button(QString("Quit"));
    int xQuitPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int yQuitPos = 425;
    quitButton->setPos(xQuitPos, yQuitPos);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
    mainmenu_scene->addItem(quitButton);
}

void Mainmenu::start()
{
    this->close();
    Game* newgame;
    newgame = new Game;
}

void Mainmenu::quit()
{
    QApplication::quit();
}
