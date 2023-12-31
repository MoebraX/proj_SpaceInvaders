#include "player.h"
#include "bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include<QDebug>
#include<QTimer>
#include "enemy.h"
#include <QAudioOutput>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    bullet = new Bullet();
    connect(bullet, &Bullet::increaseScore, this, &Player::increaseScoreSlot);
    connect(bullet, &Bullet::hitEnemy, this, &Player::bulletHit);
    bullettimer = new QTimer();
    connect(bullettimer,SIGNAL(timeout()), bullet, SLOT(move()));

    bulletSound = new QMediaPlayer();

    QAudioOutput* audioOutput = new QAudioOutput;
    bulletSound->setAudioOutput(audioOutput);

    bulletSound->setSource(QUrl("qrc:/sounds/shoot.wav"));

    //
    //bulletSound->play();
    //setGRaphics


    QPixmap originalPixmap(":/Images/spaceShip.png");  // Replace with the path to your image

    // Resize the pixmap without maintaining the aspect ratio
    QPixmap resizedPixmap = originalPixmap.scaled(50, 50, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    //Becareful: If you change the scale of spaceship, also adjust the pos() of bullet

    // Set the resized pixmap as the image for QGraphicsPixmapItem
    setPixmap(resizedPixmap);

}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(pos().x() > 0)
         setPos(x() - 10, y());
    }
    else if( event->key() == Qt::Key_Right)
    {
        if(pos().x() + 100 < 800)
         setPos(x() + 10, y());
    }

    else if(event->key() == Qt::Key_Space)
    {
        //emit testsignal();
        if(bullet->flag==true)
        {
         bullet->flag=false;
         bullet->setPos(x() + 20, y()-10);
          scene()->addItem(bullet);
          bulletSound->play();
          //play bullet sound
          if(bulletSound->mediaStatus() == QMediaPlayer::PlayingState)
          {
              bulletSound->setPosition(0);
          }
          else if(bulletSound->mediaStatus() == QMediaPlayer::StoppedState)
          {
              bulletSound->play();
          }
          bullettimer->start(50);
        }

        //qDebug() << "Bullet sound media state:" << bulletSound->mediaStatus();
    }
}

void Player::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);

}

void Player::increaseScoreSlot(int value)
{
    emit increaseScoreSignal(value);
}

void Player::bulletHit()
{
    bullettimer->stop();
    bullet->flag=true;
}
