#include <QFontDatabase>
#include "score.h"
#include <QGraphicsScene>
#include <QFont>
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::green);
    int fontId = QFontDatabase::addApplicationFont(":/fonts/pixel.ttf");
    QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont font(fontFamily);
    font.setPointSize(11);
    setFont(font);

}

void Score::increase(int value)
{
    score=score + value;
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore()
{
    return score;
}

void Score::increaseScore(int score_value)
{
    this->increase(score_value);
}
