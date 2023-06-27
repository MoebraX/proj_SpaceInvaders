#ifndef BRICK_H
#define BRICK_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include<QString>
#include <QList>

class Brick : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:

    Brick(int x, int y, bool issquare1, int rotation_degree1=0);
    void setSprite(bool issquare, int index, int rotation_degree=0);

    int HP=4;
    bool issquare;
    int rotation_degree;
    static inline QList<QString> square_sprite={":/sounds/assets/shalvar_sqare_XXX.png",":/sounds/assets/shalvar_sqare_XX.png",":/sounds/assets/shalvar_sqare_X.png",":/sounds/assets/shalvar_sqare.png"};
    static inline QList<QString> rectangle_sprite={":/sounds/assets/shalvar_rectangle_XXX.png",":/sounds/assets/shalvar_rectangle_XX.png",":/sounds/assets/shalvar_rectangle_X.png",":/sounds/assets/shalvar_rectangle.png"};
    void decreaseHP();

public slots:


signals:

};

#endif // BRICK_H
