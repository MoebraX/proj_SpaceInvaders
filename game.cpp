#include <QApplication>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QAudioOutput>
#include <QTime>
#include <QList>
#include <QRandomGenerator>

#include <endscreen.h>
#include "game.h"
#include "button.h"
#include "enemy.h"
#include "mainmenu.h"
#include "brick.h"

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
    connect(this, SIGNAL(decreaseHealthConnectorSignal()), health, SLOT(decreaseSlot()));
    connect(health, SIGNAL(gameover()), this, SLOT(displayGameover()));
    health->setPos(health->x(), health->y() + 25);
    scene->addItem(health);

    //Create player
    Player * player = new Player();
    connect(player, &Player::testsignal, this , &Game::displayGameover);
    connect(player, &Player::increaseScoreSignal, score, &Score::increaseScore);
    player ->setPos(100,100); // to always generate in the middle
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add to the scene
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


    player->setPos(view->width()/2, view->height() - (player->pixmap().height() + 20));


    //spawn enemies
    spawnEnemies();
    enemyshoot_timer= new QTimer;
    connect(enemyshoot_timer ,SIGNAL(timeout()) ,this, SLOT(enemiesShoot()));
    enemyshoot_timer->start(1000);

    //spawn Bricks
    spawnBricks();

    //wire musicbox and play background music
    QMediaPlayer *  music = new QMediaPlayer();
    QAudioOutput* audioOutput = new QAudioOutput;
    music->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.3);
    music->setSource(QUrl("qrc:/sounds/assets/space invaders - loop.ogg"));
    music->play();
}

void Game::displayGameover()
{
    enemyshoot_timer->stop();
    QMediaPlayer *  music = new QMediaPlayer();
    QAudioOutput* audioOutput = new QAudioOutput;
    music->setAudioOutput(audioOutput);
    music->setSource(QUrl("qrc:/sounds/assets/GameOver.wav"));
    music->play();

    //Black Screen
    QGraphicsRectItem *black = new QGraphicsRectItem(sceneRect());
    black->setBrush(QBrush(Qt::black));
    scene->addItem(black);
    //black->setFlag(QGraphicsItem::ItemIsFocusable);
    //black->setFocus();

    //GameOver text
    int fontId = QFontDatabase::addApplicationFont(":/fonts/pixel.ttf");
    QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont font(fontFamily);
    font.setPointSize(50);
    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("Game\nOver"));
    titleText->setFont(font);
    titleText->setDefaultTextColor(Qt::red);
    int xTitlePos = this->width()/2 - titleText->boundingRect().width()/2;
    int yTitlePos = 300;
    titleText->setPos(xTitlePos-10, yTitlePos-50);
    scene->addItem(titleText);
    //titleText->setFlag(QGraphicsItem::ItemIsFocusable);
   // titleText->setFocus();
    QTimer::singleShot(5000, this, SLOT(gameoverSlot()));
}


void Game::gameoverSlot()
{
    this->close();
    Mainmenu* mainmenu = new Mainmenu;
    this->deleteLater();
}


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

    //AlienBug::all_Bugs_downrow={bug1,bug2};
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
}

template<typename T>
void Game::chooseShooter(QList<T*> available_aliens, int chance)
{
    int randomNumber = QRandomGenerator::global()->bounded(chance);
    if(randomNumber%chance == 0)
    {
        randomNumber = QRandomGenerator::global()->bounded(available_aliens.size());
        connect(available_aliens[randomNumber], SIGNAL(decreaseHealthConnectorSignal()), this, SLOT(decreaseHealthConnectorSlot()));
        available_aliens[randomNumber]->shoot();
    }
}

void Game::enemiesShoot()
{
    //2 bar call kardane chooseShooter, baraye Bug ha va Okhtapoos ha.
    //Mechanism shoot be in soorat ast ke dar har baze zamani, agar
    //khosh shans bashim va chooseShooter ejra shavad, in shans
    //vojood darad ke dobare ham ba shans nesf yek enemy be soorate
    //random shoot konad. In stack edame peyda mikonad ta zamani ke
    //khosh shans nabashim.

    chooseShooter(AlienBug::all_Bugs, 4);
    chooseShooter(AlienOkhtapoos::all_Okhtapooses, 2);
}

void Game::decreaseHealthConnectorSlot()
{
    emit decreaseHealthConnectorSignal();
}

void Game::spawnAStackOfBricks(int x, int y, int len)
{
    Brick* brick1 = new Brick(x-len,y,1);
    scene->addItem(brick1);
    Brick* brick2 = new Brick(x,y,1);
    scene->addItem(brick2);
    Brick* brick3 = new Brick(x-2*len,y,0,180);
    scene->addItem(brick3);
    Brick* brick4 = new Brick(x+len,y,0,270);
    scene->addItem(brick4);
    Brick* brick5 = new Brick(x-len,y+len,0);
    scene->addItem(brick5);
    Brick* brick6 = new Brick(x,y+len,0,90);
    scene->addItem(brick6);
    Brick* brick7 = new Brick(x-2*len,y+len,1);
    scene->addItem(brick7);
    Brick* brick8 = new Brick(x+len,y+len,1);
    scene->addItem(brick8);
    Brick* brick9 = new Brick(x-2*len,y+2*len,1);
    scene->addItem(brick9);
    Brick* brick10 = new Brick(x+len,y+2*len,1);
    scene->addItem(brick10);
}

void Game::spawnBricks()
{
    int len=15;
    int distance =(800-4*4*len)/5;
    int x=distance+2*len, y=400;
    //First stack of bricks:
    spawnAStackOfBricks(x,y,len);

    //Second stack of bricks:
    x=x+distance+4*len;
    spawnAStackOfBricks(x,y,len);

    //Third stack of bricks:
    x=x+distance+4*len;
    spawnAStackOfBricks(x,y,len);

    //Forth stack of bricks:
    x=x+distance+4*len;
    spawnAStackOfBricks(x,y,len);
}
