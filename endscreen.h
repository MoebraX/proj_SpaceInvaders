#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include <QObject>
#include <QGraphicsView>
#include <QTimer>
#include <QWidget>
#include <QApplication>
#include <QGraphicsScene>

class Endscreen : public QGraphicsView
{
    Q_OBJECT
public:
    Endscreen(bool iswin);
    //int score;

signals:

};

#endif // ENDSCREEN_H
