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
    Enemy(QGraphicsItem *parent = 0);
    int health=1;
    int score_value=1;
    QString sprite=":/Images/Invaders.png";

    void setSprite(QString address);

public slots:
    void move();


signals:
    void destroyed(int point);
};


#endif // ENEMY_H
