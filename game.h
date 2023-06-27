#ifndef GAME_H
#define GAME_H

#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsScene>
#include "player.h"
#include <QGraphicsView>
#include <QTimer>
#include <QWidget>
#include "health.h"
#include "score.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game();

    void displayGameover();
    void spawnEnemies();
    void spawnAStackOfBricks(int x, int y, int len);
    void spawnBricks();

    template<typename T>
    bool chooseShooter(QList<T*> available_aliens, int chance);
    //void displaySettingsMenu();

    QGraphicsScene * scene;
    Player *player;
    Score *score;
    Health *health;
    int sceneWidth;
    int sceneHeight;

public slots:
    void enemiesShoot();
    void decreaseHealthConnectorSlot();

signals:
    void decreaseHealthConnectorSignal();

};

#endif // GAME_H
