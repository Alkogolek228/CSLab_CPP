#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(qreal x, qreal y, qreal width, qreal height);

    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    qreal x() const;
    qreal y() const;
    qreal width() const;
    qreal height() const;

private:
    qreal m_x;
    qreal m_y;
    qreal m_width;
    qreal m_height;
};

#endif // RECTANGLE_H
