#ifndef HEALTH_H
#define HEALTH_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QGraphicsScene>

class Health : public QGraphicsTextItem
{
    Q_OBJECT
public:
    explicit Health(QObject *parent = nullptr);
    void decrease();
    int getHealth();

public slots:
    void decreaseSlot();

private:
    int health;
    bool gameover();
};

#endif // HEALTH_H
