#ifndef ENEMY_H
#define ENEMY_H



#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include<QString>
#include <QTimer>

class Enemy : public QObject ,  public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(int x=0, int y=0, QGraphicsItem *parent = 0);
    int health=1;
    int score_value=1;
    QString sprite=":/Images/Invaders.png";
    int pos_x=0, pos_y=0;
    int initial_x=0;
    int initial_y=0;
    int movement_counter=0;

    void setSprite(QString address);

private:

public slots:
    void move();


signals:
    void destroyed(int point);
};


class AlienKachal : public Enemy
{
public:
    AlienKachal(int x=0, int y=0)
    {
        setSprite(":/Images/assets/Alien_Kachal_01__white.png");
        health=1;
        score_value=1;
        pos_x=x;
        pos_y=y;
        initial_x=x;
        initial_y=y;
        setPos(pos_x, pos_y);
        //draw the rect
        setPixmap(QPixmap(sprite));
        QPixmap originalPixmap(sprite);  // Replace with the path to your image

        // Resize the pixmap without maintaining the aspect ratio
        QPixmap resizedPixmap = originalPixmap.scaled(35, 35,Qt::IgnoreAspectRatio, Qt::SmoothTransformation );

        // Set the resized pixmap as the image for QGraphicsPixmapItem
        setPixmap(resizedPixmap);
    }
};

class AlienBug : public Enemy
{
public:
    AlienBug(int x=0, int y=0)
    {
        setSprite(":/Images/assets/Alien_Bug_01__white.png");
        health=1;
        score_value=1;
        pos_x=x;
        pos_y=y;
        initial_x=x;
        initial_y=y;
        setPos(pos_x, pos_y);
        //draw the rect
        setPixmap(QPixmap(sprite));
        QPixmap originalPixmap(sprite);  // Replace with the path to your image

        // Resize the pixmap without maintaining the aspect ratio
        QPixmap resizedPixmap = originalPixmap.scaled(35, 35,Qt::IgnoreAspectRatio, Qt::SmoothTransformation );

        // Set the resized pixmap as the image for QGraphicsPixmapItem
        setPixmap(resizedPixmap);
    }
};

class AlienOkhtapoos : public Enemy
{
public:
    AlienOkhtapoos(int x=0, int y=0)
    {
        setSprite(":/Images/assets/Alien_Okhtapoos_01__white.png");
        health=1;
        score_value=1;
        pos_x=x;
        pos_y=y;
        initial_x=x;
        initial_y=y;
        setPos(pos_x, pos_y);
        //draw the rect
        setPixmap(QPixmap(sprite));
        QPixmap originalPixmap(sprite);  // Replace with the path to your image

        // Resize the pixmap without maintaining the aspect ratio
        QPixmap resizedPixmap = originalPixmap.scaled(35, 35,Qt::IgnoreAspectRatio, Qt::SmoothTransformation );

        // Set the resized pixmap as the image for QGraphicsPixmapItem
        setPixmap(resizedPixmap);
    }
};


#endif // ENEMY_H
