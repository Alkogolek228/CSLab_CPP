#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QtWidgets>

class Shape : public QGraphicsItem
{
public:
    Shape();

    virtual QRectF boundingRect() const = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) = 0;
};

#endif // SHAPE_H
