

#include <QApplication>
#include "game.h"
#include "mainmenu.h"
Game *game;
Mainmenu *mainmenu;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   // game = new Game();
    //game->show();
    //game->displayMainmenu();
    mainmenu = new Mainmenu();
    mainmenu->show();

    return a.exec();
}

