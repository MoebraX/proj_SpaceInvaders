#include "enemybullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <Qdebug>
#include <QList>
#include "enemy.h"
#include "game.h"
#include "player.h"

EnemyBullet::EnemyBullet(QString sprite=":/Images/bullet.png")
{
    //draw graphics
    QPixmap originalPixmap(sprite);

    // Resize the pixmap without maintaining the aspect ratio
    QPixmap resizedPixmap = originalPixmap.scaled(10, 30,Qt::IgnoreAspectRatio, Qt::SmoothTransformation );

    // Set the resized pixmap as the image for QGraphicsPixmapItem
    setPixmap(resizedPixmap);



    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void EnemyBullet::move()
{
    // check for collision with enemies
    QList<QGraphicsItem *> colliding_items =collidingItems();
    for(auto const i : colliding_items)
    {
        Player* hit_player = dynamic_cast<Player*>(i);
        if(hit_player    != nullptr)
        {
            //emit signal to decrease player's health
            emit decreaseHealth();

            //remove bullet from the scene (will get deleted soon)
            timer->stop();
            scene()->removeItem(this);
        }
    }
    // move the bullet downwards
    setPos(x(), y() + 10);

    //Remove the bullet if it goes out of the window
    if(pos().y() + pixmap().height() > 600)
    {
        scene()->removeItem(this);
        timer->stop();
        delete(this);
    }
}
