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
    //void displaySettingsMenu();

    QGraphicsScene * scene;
    Player *player;
    Score *score;
    Health *health;
    int sceneWidth;
    int sceneHeight;

public slots:




};

#endif // GAME_H
