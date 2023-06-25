#ifndef MAINMENU_H
#define MAINMENU_H

#include "mainwindow.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsTextItem>
#include <QFontDatabase>
#include <QKeyEvent>

class Mainmenu: public QGraphicsView
{
    Q_OBJECT
public:
    Mainmenu();


    QGraphicsScene* mainmenu_scene;
    int sceneWidth;
    int sceneHeight;

public slots:
    void start();
    void quit();
};

#endif // MAINMENU_H
