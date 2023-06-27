#ifndef GAME_H
#define GAME_H

#include "mainwindow.h"
#include "player.h"
#include "health.h"
#include "score.h"

#include <QGraphicsView>
#include <QTimer>
#include <QWidget>
#include <QApplication>
#include <QGraphicsScene>

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();
    void spawnEnemies();
    void spawnAStackOfBricks(int x, int y, int len);
    void spawnBricks();

    template<typename T>
    void chooseShooter(QList<T*> available_aliens, int chance);


    QGraphicsScene * scene;
    Player *player;
    Score *score;
    Health *health;
    int sceneWidth;
    int sceneHeight;

public slots:
    void enemiesShoot();
    void decreaseHealthConnectorSlot();
    void displayGameover();

signals:
    void decreaseHealthConnectorSignal();

};

#endif // GAME_H
