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
    QPixmap originalPixmap(sprite);
    QPixmap resizedPixmap = originalPixmap.scaled(50, 50,Qt::IgnoreAspectRatio, Qt::SmoothTransformation );
    setPixmap(resizedPixmap);

    //connect
    QTimer * timer = new QTimer(this );
    connect(timer,SIGNAL(timeout()), this, SLOT(move()));
    timer->start(1000);
}

void Enemy::setSprite(QString primary, QString secondary)
{
    sprite=primary;
    secondary_sprite=secondary;

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
            dance();
        }
        else if(pos_x-initial_x >= 5*10)
        {
            pos_y+=30;
            setPos(pos_x,pos_y);
            dance();
            movement_counter++;
        }
    }

    else if(movement_counter%2==1)
    {
        if(pos_x-initial_x > (-5)*10)
        {
            pos_x-=10;
            setPos(pos_x,pos_y);
            dance();
        }
        else if(pos_x-initial_x <= (-5)*10)
        {
            pos_y+=30;
            setPos(pos_x,pos_y);
            dance();
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

void Enemy::dance()
{
    QString holder = sprite;
    sprite = secondary_sprite;
    secondary_sprite = holder;
    setPixmap(QPixmap(sprite));
    QPixmap originalPixmap(sprite);
    QPixmap resizedPixmap = originalPixmap.scaled(35, 40,Qt::IgnoreAspectRatio, Qt::SmoothTransformation );
    setPixmap(resizedPixmap);
}
