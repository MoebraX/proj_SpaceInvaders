#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include "bullet.h"

class Player : public QObject,  public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent * event);

    Bullet* bullet;
public slots:
    void spawn();
    void increaseScoreSlot(int value);
    void bulletHit();

signals:
    void testsignal();
    void increaseScoreSignal(int value);
private:
    QMediaPlayer * bulletSound;
    QTimer * bullettimer;

};

#endif // PLAYER_H
