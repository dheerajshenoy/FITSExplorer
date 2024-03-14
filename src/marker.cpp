#include "marker.h"
#include <QColor>
#include <QPen>

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
    m_ellipse->setPen(QPen(color));
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

void Marker::addVisualizer()
{
    QGraphicsEllipseItem *visualizer = new QGraphicsEllipseItem(m_ellipse);
    visualizer->setPen(QColor(Qt::green));
    visualizer->setScale(1.5);
    this->addToGroup(visualizer);
}
