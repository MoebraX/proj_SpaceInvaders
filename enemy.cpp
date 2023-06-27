#include "enemy.h"
#include <QList>
#include <stdlib.h>
#include <QRandomGenerator>
#include "game.h"
#include "bullet.h"
#include "enemybullet.h"

extern Game *game;
Enemy::Enemy (int x, int y, QGraphicsItem *parent ) : QObject(), QGraphicsPixmapItem()
{
    pos_x=x;
    pos_y=y;
    initial_x=x;
    initial_y=y;
    setPos(pos_x, pos_y);
    //draw the rect
    setPixmap(QPixmap(sprite));
    QPixmap originalPixmap(sprite);  // Replace with the path to your image

    // Resize the pixmap without maintaining the aspect ratio
    QPixmap resizedPixmap = originalPixmap.scaled(50, 50,Qt::IgnoreAspectRatio, Qt::SmoothTransformation );

    // Set the resized pixmap as the image for QGraphicsPixmapItem
    setPixmap(resizedPixmap);

    //connect
    QTimer * timer = new QTimer(this );
    connect(timer,SIGNAL(timeout()), this, SLOT(move()));

    timer->start(900);
}

void Enemy::setSprite(QString address)
{
    sprite=address;
}

void Enemy::move()
{
    //All enemies movement pattern
    if(movement_counter%2==0)
    {
        if(pos_x-initial_x < 5*10)
        {
            pos_x+=10;
            setPos(pos_x,pos_y);
        }
        else if(pos_x-initial_x >= 5*10)
        {
            pos_y+=30;
            setPos(pos_x,pos_y);
            movement_counter++;
        }
    }

    else if(movement_counter%2==1)
    {
        if(pos_x-initial_x > (-5)*10)
        {
            pos_x-=10;
            setPos(pos_x,pos_y);
        }
        else if(pos_x-initial_x <= (-5)*10)
        {
            pos_y+=30;
            setPos(pos_x,pos_y);
            movement_counter++;
        }
    }
}

void Enemy::shoot()
{
    EnemyBullet* bullet = new EnemyBullet(":/Images/bullet.png");
    connect(bullet, SIGNAL(decreaseHealth()), this, SLOT(decreaseHealthConnectorSlot()));
    bullet->setPos(x() + 25 , y());
    scene()->addItem(bullet);
    //connect(bullet, SIGNAL(hit()), this, SLOT(bulletHit()));

}

void Enemy::decreaseHealthConnectorSlot()
{
    emit decreaseHealthConnectorSignal();
}
