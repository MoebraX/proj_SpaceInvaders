#include "brick.h"

Brick::Brick(int x, int y, bool issquare1):  QObject(), QGraphicsPixmapItem()
{
    issquare=issquare1;

    //draw the rect
    setPos(x, y);
    setSprite(issquare, HP-1);

}
void Brick::setSprite(bool issquare, int index)
{
    if(issquare==1)
    {
        setPixmap(QPixmap(square_sprite[index]));
        QPixmap originalPixmap(square_sprite[index]);
        QPixmap resizedPixmap = originalPixmap.scaled(30, 30,Qt::IgnoreAspectRatio, Qt::SmoothTransformation );
        setPixmap(resizedPixmap);
    }
    else
    {
        setPixmap(QPixmap(rectangle_sprite[index]));
        QPixmap originalPixmap(rectangle_sprite[index]);
        QPixmap resizedPixmap = originalPixmap.scaled(30, 30,Qt::IgnoreAspectRatio, Qt::SmoothTransformation );
        setPixmap(resizedPixmap);
    }

}

void Brick::decreaseHP()
{
    HP--;
    if(HP==0)
    {
        deleteLater();
    }
    else
        setSprite(issquare, HP-1);
}
