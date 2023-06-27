#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QFontDatabase>

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setRect(0, 0, 200, 50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBrush(brush);

    // Draw text
    text = new QGraphicsTextItem(name, this);
    QFont font;
    int fontId = QFontDatabase::addApplicationFont(":/fonts/pixel.ttf");
    QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
    font.setFamily(fontFamily);
    font.setPointSize(12); // Adjust the font size to your preference
    text->setFont(font);
    text->setDefaultTextColor(Qt::green);
    text->setPos(rect().width()/2 - text->boundingRect().width()/2,
                 rect().height()/2 - text->boundingRect().height()/2);

    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black); // Adjust the color to your preference
    setBrush(brush);
    QFont font = text->font();
    font.setPointSize(14); // Increase the font size when hovering
    text->setFont(font);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBrush(brush);
    QFont font = text->font();
    font.setPointSize(12); // Restore the default font size
    text->setFont(font);
}
