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
    template<typename T>
    bool chooseShooter(int target_x, QList<T*> available_aliens);
    //void displaySettingsMenu();

    QGraphicsScene * scene;
    Player *player;
    Score *score;
    Health *health;
    int sceneWidth;
    int sceneHeight;

public slots:
    void enemiesShoot(int target_x);
    void decreaseHealthConnectorSlot();

signals:
    void decreaseHealthConnectorSignal();

};

#endif // GAME_H
