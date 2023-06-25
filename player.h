#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
class Player : public QObject,  public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player(QGraphicsItem *parent = 0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
    void increaseScoreSlot(int value);

signals:
    void testsignal();
    void increaseScoreSignal(int value);
private:
    QMediaPlayer * bulletSound;

};

#endif // PLAYER_H
