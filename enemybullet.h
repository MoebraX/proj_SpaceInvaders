#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <enemy.h>
#include <QString>
#include <QGraphicsItem>
#include <QTimer>

class EnemyBullet : public QObject ,  public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit EnemyBullet(QString sprite);
    bool flag=true;
    QTimer* timer;


signals:
    void decreaseHealth();

public slots:
    void move();

};

#endif // ENEMYBULLET_H
