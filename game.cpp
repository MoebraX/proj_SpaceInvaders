#include <QApplication>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QAudioOutput>
#include <QTime>

#include "game.h"
#include "button.h"
#include "enemy.h"
#include "mainmenu.h"

Game::Game()
{
    //create secene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800,600);// make the secen 600 * 800 instead of infinity by infinity
    setBackgroundBrush(QBrush(QImage(":/Images/Background.png")));

    //make the newly created scene the scene to visualize
    //it ccan be used to visualize scene
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //Create score
    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);

    //create an item to put into the scene
    Player * player = new Player();
    connect(player, &Player::testsignal, this , &Game::displayGameover);
    connect(player, &Player::increaseScoreSignal, score, &Score::increaseScore);
    player ->setPos(100,100); // to always generate in the middle
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add to the senec
    scene->addItem(player);

    // add view
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0, 800,600);
    QImage backgroundImage(":/Images/Background.png");
    QImage scaledImage = backgroundImage.scaled(view->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    view->setBackgroundBrush(QBrush(scaledImage));


    player->setPos(view->width()/2, view->height() - player->pixmap().height());


    //spawn enemies
    spawnEnemies();

    //play background
    QMediaPlayer *  music = new QMediaPlayer();

    QAudioOutput* audioOutput = new QAudioOutput;
    music->setAudioOutput(audioOutput);

    music->setSource(QUrl("qrc:/sounds/assets/space invaders - loop.ogg"));

    music->play();


    qDebug() << "Background music state:" << music->mediaStatus();

}

void Game::displayGameover()
{
    //create gameover text
    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("Game Over"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);
    titleText->setDefaultTextColor(Qt::yellow);
    int xTitlePos = this->width()/2 - titleText->boundingRect().width()/2;
    int yTitlePos = 150;
    titleText->setPos(xTitlePos-10, yTitlePos-50);
    scene->addItem(titleText);
    QGraphicsTextItem *text = new QGraphicsTextItem(QString("Press Space to return to home screen"));
    text->setFont(QFont("comic sans", 20));
    text->setDefaultTextColor((Qt::white));
    text->setPos(xTitlePos,yTitlePos + 20);
    scene->addItem(text);

    //Close the window
    //TO DO: press key = close
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    Mainmenu* mainmenu;
    mainmenu=new Mainmenu;
    mainmenu->show();
    delete this;

   /* // create "Retry" button
    Button *retryButton = new Button(QString("Retry"));
    int xRetryPos = this->width()/2 - retryButton->boundingRect().width()/2;
    int yRetryPos = 275;
    retryButton->setPos(xRetryPos, yRetryPos);
    connect(retryButton, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(retryButton);

    Button *settingsButton = new Button(QString("Settings"));
    int xSettingsPos = this->width()/2 - settingsButton->boundingRect().width()/2;
    int ySettingsPos = 350;
    settingsButton->setPos(xSettingsPos, ySettingsPos);
    connect(settingsButton, SIGNAL(clicked()), this, SLOT(displaySettingsMenu()));
    scene->addItem(settingsButton);

    // create quit button
    Button *quitButton = new Button(QString("Quit"));
    int xQuitPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int yQuitPos = 425;
    quitButton->setPos(xQuitPos, yQuitPos);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);
*/


}

/*void Game::displaySettingsMenu()
{

    // clean up the screen
    scene->clear();

    // create "Settings" text
    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("Settings"));
    QFont titleFont("comic sans", 50);
    titleText->setFont(titleFont);
    int xTitlePos = this->width()/2 - titleText->boundingRect().width()/2;
    int yTitlePos = 150;
    titleText->setPos(xTitlePos, yTitlePos);
    scene->addItem(titleText);

    // TO DO: List to select different resolution versions (480p, 720p, 1080p)

    // TO DO: Re-bind keys

    // TO DO: Replace "quit" button with a "back" button

    // create quit button
    Button *quitButton = new Button(QString("Quit"));
    int xQuitPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int yQuitPos = 425;
    quitButton->setPos(xQuitPos, yQuitPos);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quitButton);

}*/


void Game::spawnEnemies()
{
    int x=148, y=40;
    int distance=12;
    int len=35;

    //Kachal Aliens:
    AlienKachal* kachal1 = new AlienKachal(x,5*y);
    scene->addItem(kachal1);
    AlienKachal* kachal2 = new AlienKachal(x+1*(distance+len),5*y);
    scene->addItem(kachal2);
    AlienKachal* kachal3 = new AlienKachal(x+2*(distance+len),5*y);
    scene->addItem(kachal3);
    AlienKachal* kachal4 = new AlienKachal(x+3*(distance+len),5*y);
    scene->addItem(kachal4);
    AlienKachal* kachal5 = new AlienKachal(x+4*(distance+len),5*y);
    scene->addItem(kachal5);
    AlienKachal* kachal6 = new AlienKachal(x+5*(distance+len),5*y);
    scene->addItem(kachal6);
    AlienKachal* kachal7 = new AlienKachal(x+6*(distance+len),5*y);
    scene->addItem(kachal7);
    AlienKachal* kachal8 = new AlienKachal(x+7*(distance+len),5*y);
    scene->addItem(kachal8);
    AlienKachal* kachal9 = new AlienKachal(x+8*(distance+len),5*y);
    scene->addItem(kachal9);
    AlienKachal* kachal10 = new AlienKachal(x+9*(distance+len),5*y);
    scene->addItem(kachal10);
    AlienKachal* kachal11 = new AlienKachal(x+10*(distance+len),5*y);
    scene->addItem(kachal11);
    //
    AlienKachal* kachal12 = new AlienKachal(x,4*y);
    scene->addItem(kachal12);
    AlienKachal* kachal13 = new AlienKachal(x+1*(distance+len),4*y);
    scene->addItem(kachal13);
    AlienKachal* kachal14 = new AlienKachal(x+2*(distance+len),4*y);
    scene->addItem(kachal14);
    AlienKachal* kachal15 = new AlienKachal(x+3*(distance+len),4*y);
    scene->addItem(kachal15);
    AlienKachal* kachal16 = new AlienKachal(x+4*(distance+len),4*y);
    scene->addItem(kachal16);
    AlienKachal* kachal17 = new AlienKachal(x+5*(distance+len),4*y);
    scene->addItem(kachal17);
    AlienKachal* kachal18 = new AlienKachal(x+6*(distance+len),4*y);
    scene->addItem(kachal18);
    AlienKachal* kachal19 = new AlienKachal(x+7*(distance+len),4*y);
    scene->addItem(kachal19);
    AlienKachal* kachal20 = new AlienKachal(x+8*(distance+len),4*y);
    scene->addItem(kachal20);
    AlienKachal* kachal21 = new AlienKachal(x+9*(distance+len),4*y);
    scene->addItem(kachal21);
    AlienKachal* kachal22 = new AlienKachal(x+10*(distance+len),4*y);
    scene->addItem(kachal22);

    //BugAliens:
    AlienBug* bug1 = new AlienBug(x,3*y);
    scene->addItem(bug1);
    AlienBug* bug2 = new AlienBug(x+1*(distance+len),3*y);
    scene->addItem(bug2);
    AlienBug* bug3 = new AlienBug(x+2*(distance+len),3*y);
    scene->addItem(bug3);
    AlienBug* bug4 = new AlienBug(x+3*(distance+len),3*y);
    scene->addItem(bug4);
    AlienBug* bug5 = new AlienBug(x+4*(distance+len),3*y);
    scene->addItem(bug5);
    AlienBug* bug6 = new AlienBug(x+5*(distance+len),3*y);
    scene->addItem(bug6);
    AlienBug* bug7 = new AlienBug(x+6*(distance+len),3*y);
    scene->addItem(bug7);
    AlienBug* bug8 = new AlienBug(x+7*(distance+len),3*y);
    scene->addItem(bug8);
    AlienBug* bug9 = new AlienBug(x+8*(distance+len),3*y);
    scene->addItem(bug9);
    AlienBug* bug10 = new AlienBug(x+9*(distance+len),3*y);
    scene->addItem(bug10);
    AlienBug* bug11 = new AlienBug(x+10*(distance+len),3*y);
    scene->addItem(bug11);
    //
    AlienBug* bug12 = new AlienBug(x,2*y);
    scene->addItem(bug12);
    AlienBug* bug13 = new AlienBug(x+1*(distance+len),2*y);
    scene->addItem(bug13);
    AlienBug* bug14 = new AlienBug(x+2*(distance+len),2*y);
    scene->addItem(bug14);
    AlienBug* bug15 = new AlienBug(x+3*(distance+len),2*y);
    scene->addItem(bug15);
    AlienBug* bug16 = new AlienBug(x+4*(distance+len),2*y);
    scene->addItem(bug16);
    AlienBug* bug17 = new AlienBug(x+5*(distance+len),2*y);
    scene->addItem(bug17);
    AlienBug* bug18 = new AlienBug(x+6*(distance+len),2*y);
    scene->addItem(bug18);
    AlienBug* bug19 = new AlienBug(x+7*(distance+len),2*y);
    scene->addItem(bug19);
    AlienBug* bug20 = new AlienBug(x+8*(distance+len),2*y);
    scene->addItem(bug20);
    AlienBug* bug21 = new AlienBug(x+9*(distance+len),2*y);
    scene->addItem(bug21);
    AlienBug* bug22 = new AlienBug(x+10*(distance+len),2*y);
    scene->addItem(bug22);

    //Okhtapoos Aliens:
    AlienOkhtapoos* okhtapoos1 = new AlienOkhtapoos(x,y);
    scene->addItem(okhtapoos1);
    AlienOkhtapoos* okhtapoos2 = new AlienOkhtapoos(x+1*(distance+len),y);
    scene->addItem(okhtapoos2);
    AlienOkhtapoos* okhtapoos3 = new AlienOkhtapoos(x+2*(distance+len),y);
    scene->addItem(okhtapoos3);
    AlienOkhtapoos* okhtapoos4 = new AlienOkhtapoos(x+3*(distance+len),y);
    scene->addItem(okhtapoos4);
    AlienOkhtapoos* okhtapoos5 = new AlienOkhtapoos(x+4*(distance+len),y);
    scene->addItem(okhtapoos5);
    AlienOkhtapoos* okhtapoos6 = new AlienOkhtapoos(x+5*(distance+len),y);
    scene->addItem(okhtapoos6);
    AlienOkhtapoos* okhtapoos7 = new AlienOkhtapoos(x+6*(distance+len),y);
    scene->addItem(okhtapoos7);
    AlienOkhtapoos* okhtapoos8 = new AlienOkhtapoos(x+7*(distance+len),y);
    scene->addItem(okhtapoos8);
    AlienOkhtapoos* okhtapoos9 = new AlienOkhtapoos(x+8*(distance+len),y);
    scene->addItem(okhtapoos9);
    AlienOkhtapoos* okhtapoos10 = new AlienOkhtapoos(x+9*(distance+len),y);
    scene->addItem(okhtapoos10);
    AlienOkhtapoos* okhtapoos11 = new AlienOkhtapoos(x+10*(distance+len),y);
    scene->addItem(okhtapoos11);

    //AlienBug* bug1 = new AlienBug(200,240);
    //scene->addItem(bug1);
    //AlienOkhtapoos* okhtapoos1 = new AlienOkhtapoos(200,260);
    //scene->addItem(okhtapoos1);



}
