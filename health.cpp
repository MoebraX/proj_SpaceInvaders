#include "health.h"
#include <QGraphicsScene>
#include <QFont>
#include "game.h"
#include <QFontDatabase>

extern Game *game;

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
    if(gameover())
    {
        game->displayGameover();
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

bool Health::gameover()
{
    return health < 1;
}

void Health::decreaseSlot()
{
    this->decrease();
}
