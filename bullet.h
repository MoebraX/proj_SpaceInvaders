#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <enemy.h>

class Bullet : public QObject ,  public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent = 0);
    bool flag=true;
public slots:
    void move();

signals:
    void increaseScore(int value);
    void hitEnemy();
};

#endif // BULLET_H
