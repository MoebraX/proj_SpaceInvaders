#include "health.h"
#include <QGraphicsScene>
#include <QFont>
#include "game.h"

<<<<<<< HEAD

=======
#include <QFontDatabase>
>>>>>>> d32ac1d8421affae453c13fa6fc8f3e7d947303c

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
