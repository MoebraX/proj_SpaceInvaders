#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <Qdebug>
#include <QList>
#include "enemy.h"
#include "game.h"

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //draw graphics
    QPixmap originalPixmap(":/Images/bullet.png");  // Replace with the path to your image

    // Resize the pixmap without maintaining the aspect ratio
    QPixmap resizedPixmap = originalPixmap.scaled(10, 20,Qt::IgnoreAspectRatio, Qt::SmoothTransformation );

    // Set the resized pixmap as the image for QGraphicsPixmapItem
    setPixmap(resizedPixmap);
}

void Bullet::move()
{
    // check for collision with enemies
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(auto const i : colliding_items)
    {
        Enemy* hit_enemy = dynamic_cast<Enemy*>(i);
        if(hit_enemy    != nullptr)
        {
            //emit signal to decrease enemy's health
            if(hit_enemy->health>1)
                hit_enemy->health--;


            //remove enemy and bullet from heap memory
            else{
                emit increaseScore(hit_enemy->score_value);
                scene()->removeItem(hit_enemy);
                delete hit_enemy;
                scene()->removeItem(this);
                emit hitEnemy();
            }
        }

    }


    // move the bullet  upwards
    setPos(x(), y() - 10);
    //Remove the bullet if it goes out of the window
    if(pos().y() + pixmap().height() < 0)
    {
        emit hitEnemy();
        scene()->removeItem(this);

    }
}
