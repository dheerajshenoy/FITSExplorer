#include "marker.h"

Marker::Marker(QGraphicsItem *parent)
    : QGraphicsItemGroup(parent)
{
}

void Marker::setMarker(QGraphicsEllipseItem *ellipse,
               QGraphicsTextItem *text,
               QString id)
{
    m_ellipse = ellipse;
    m_text = text;
    m_id = id;

    this->addToGroup(ellipse);
    this->addToGroup(text);
}

void Marker::setShapeColor(QColor color)
{
    m_ellipse->setBrush(QBrush(color));
}

void Marker::setShape(QGraphicsItem *)
{
}

void Marker::setText(QString text)
{
    m_text->setPlainText(text);
}

void Marker::setTextItem(QGraphicsTextItem *textItem)
{
    m_text = textItem;
}


