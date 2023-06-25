
#include "score.h"
#include <QGraphicsScene>
#include <QFont>
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;

    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 16));
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
