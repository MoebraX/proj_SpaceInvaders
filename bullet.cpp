#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <Qdebug>
#include <QList>
#include "enemy.h"
#include "game.h"
#include "brick.h"

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
    //check for collision with enemies or Bricks
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(auto const i : colliding_items)
    {
        Enemy* hit_enemy = dynamic_cast<Enemy*>(i);
        //Brick* hit_brick = dynamic_cast<Brick*>(i);
        if(hit_enemy    != nullptr)
        {
            //decrease enemy's health
            if(hit_enemy->health>1)
                hit_enemy->health--;
            //remove enemy from heap memory and related QList
            else
            {
                scene()->removeItem(hit_enemy);
                int index=AlienBug::all_Bugs.indexOf(static_cast<AlienBug*>(hit_enemy));
                if(index!=-1)
                {
                    AlienBug::all_Bugs.takeAt(index);
                }
                else
                {
                    int index=AlienOkhtapoos::all_Okhtapooses.indexOf(static_cast<AlienOkhtapoos*>(hit_enemy));
                    if(index!=-1)
                    {
                        AlienOkhtapoos::all_Okhtapooses.takeAt(index);
                    }
                }
                emit increaseScore(hit_enemy->score_value);
                delete hit_enemy;
                scene()->removeItem(this);
            }
            emit hitEnemy();
        }
    }

    bool hit_brick = false;
    for(auto const i : colliding_items)
    {
        Brick* brick = dynamic_cast<Brick*>(i);
        //Check for collision with Brick
        if(brick  != nullptr && hit_brick==false)
        {
            //decrease brick's health
            brick->decreaseHP();
            hit_brick = true;
        }
    }

    if(hit_brick)
    {
        scene()->removeItem(this);
        emit hitEnemy();
        return;
    }

    // move the bullet  upwards
    setPos(x(), y() - 20);
    //Remove the bullet if it goes out of the window
    if(pos().y() + pixmap().height() < 0)
    {
        emit hitEnemy();
        scene()->removeItem(this);

    }
}

/*
void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    bool hit_brick = false;

    for(auto const i : colliding_items)
    {
        // Check for collision with Brick
        Brick* brick = dynamic_cast<Brick*>(i);
        if(brick != nullptr)
        {
            // decrease brick's health
            brick->decreaseHP();
            hit_brick = true;
        }

        // Check for collision with Enemy
        Enemy* hit_enemy = dynamic_cast<Enemy*>(i);
        if(hit_enemy != nullptr)
        {
            //decrease enemy's health
            if(hit_enemy->health>1)
                hit_enemy->health--;
            //remove enemy from heap memory and related QList
            else
            {
                scene()->removeItem(hit_enemy);
                int index=AlienBug::all_Bugs.indexOf(static_cast<AlienBug*>(hit_enemy));
                if(index!=-1)
                {
                    AlienBug::all_Bugs.takeAt(index);
                }
                else
                {
                    int index=AlienOkhtapoos::all_Okhtapooses.indexOf(static_cast<AlienOkhtapoos*>(hit_enemy));
                    if(index!=-1)
                    {
                        AlienOkhtapoos::all_Okhtapooses.takeAt(index);
                    }
                }
                emit increaseScore(hit_enemy->score_value);
                delete hit_enemy;
                scene()->removeItem(this);
            }
        }
    }

    if(hit_brick)
    {
        scene()->removeItem(this);
        emit hitEnemy();
        return;
    }

    // move the bullet upwards
    setPos(x(), y() - 20);

    // remove the bullet if it goes out of the window
    if(pos().y() + pixmap().height() < 0)
    {
        emit hitEnemy();
        scene()->removeItem(this);
    }
}
*/
