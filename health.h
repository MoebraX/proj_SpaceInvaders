#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QObject>

class Health : public QGraphicsTextItem
{
    Q_OBJECT
public:
    Health();
    void decrease();
    int getHealth();

public slots:
    void decreaseSlot();

private:
    int health;
    bool gameover();

};


#endif // HEALTH_H
