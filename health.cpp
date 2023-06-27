#include "health.h"
#include <QGraphicsScene>
#include <QFont>
#include "game.h"
#include <QFontDatabase>

Health::Health()
{
    health = 3;
    setPlainText("Health: " + QString::number(health));
    setDefaultTextColor(Qt::green);

    int fontId = QFontDatabase::addApplicationFont(":/fonts/pixel.ttf");
    QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);

    QFont font(fontFamily);
    font.setPointSize(11);
    setFont(font);
}

void Health::decrease()
{
    if(health>0)
        health--;
    if(health==0)
    {
        setPlainText("Health: " + QString::number(health));
        health--;
        emit gameover();
    }
    else if(health>0)
    {
        setPlainText("Health: " + QString::number(health));
    }

}

int Health::getHealth()
{
    return health;
}

void Health::decreaseSlot()
{
    this->decrease();
}
