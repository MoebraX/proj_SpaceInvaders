
#include <QIcon>
#include <QApplication>
#include "game.h"
#include "mainmenu.h"
Game *game;
Mainmenu *mainmenu;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QCoreApplication::setApplicationName("Space-Invaders");
    QIcon icon(":Images/Icon.png");
    QApplication::setWindowIcon(icon);

    mainmenu = new Mainmenu();
    mainmenu->show();

    return a.exec();
}

