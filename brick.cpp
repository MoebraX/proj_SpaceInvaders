#include "brick.h"

Brick::Brick(int x, int y, bool issquare1, int rotation_degree1):  QObject(), QGraphicsPixmapItem()
{
    issquare=issquare1;
    rotation_degree=rotation_degree1;
    //draw the rect
    setPos(x, y);
    setSprite(issquare, HP-1, rotation_degree);

}
void Brick::setSprite(bool issquare, int index, int rotation_degree)
{
    if(issquare==1)
    {
        QPixmap originalPixmap(square_sprite[index]);

        // Rotate the pixmap
        QTransform transform;
        transform.rotate(rotation_degree);
        QPixmap rotatedPixmap = originalPixmap.transformed(transform);

        QPixmap resizedPixmap = rotatedPixmap.scaled(15, 15,Qt::IgnoreAspectRatio, Qt::SmoothTransformation );
        setPixmap(resizedPixmap);
    }
    else
    {
        QPixmap originalPixmap(rectangle_sprite[index]);

        // Rotate the pixmap
        QTransform transform;
        transform.rotate(rotation_degree);
        QPixmap rotatedPixmap = originalPixmap.transformed(transform);

        QPixmap resizedPixmap = rotatedPixmap.scaled(15, 15,Qt::IgnoreAspectRatio, Qt::SmoothTransformation );
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
        setSprite(issquare, HP-1, rotation_degree);
}
