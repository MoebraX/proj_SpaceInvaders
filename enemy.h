#ifndef ENEMY_H
#define ENEMY_H



#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include<QString>

class Enemy : public QObject ,  public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(int x=0, int y=0, QGraphicsItem *parent = 0);
    int health=1;
    int score_value=1;
    QString sprite=":/Images/Invaders.png";
    int pos_x=0, pos_y=0;

    void setSprite(QString address);

private:
    int initial_x=0;
    int initial_y=0;
    int movement_counter=0;
public slots:
    void move();


signals:
    void destroyed(int point);
};


#endif // ENEMY_H
