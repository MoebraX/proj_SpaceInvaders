#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QGraphicsScene>
class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem * parent = 0);
    void increase(int value);
    int getScore();

private:
    int score;

public slots:
    void increaseScore(int score_value);
};

#endif // SCORE_H
