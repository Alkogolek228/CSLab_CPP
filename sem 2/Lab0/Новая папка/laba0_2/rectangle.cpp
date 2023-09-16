#include "Rectangle.h"

Rectangle::Rectangle(qreal x, qreal y, qreal width, qreal height)
    : m_x(x)
    , m_y(y)
    , m_width(width)
    , m_height(height)
{
}

QRectF Rectangle::boundingRect() const
{
    return QRectF(m_x, m_y, m_width, m_height);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(m_x, m_y, m_width, m_height);
}

qreal Rectangle::x() const
{
    return m_x;
}

qreal Rectangle::y() const
{
    return m_y;
}

qreal Rectangle::width() const
{
    return m_width;
}

qreal Rectangle::height() const
{
    return m_height;
}
