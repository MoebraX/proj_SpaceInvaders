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
    health--;
    if(health==0)
    {
        emit gameover();
    }
    else
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
