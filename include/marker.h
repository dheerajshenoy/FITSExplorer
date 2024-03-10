#ifndef MARKER_H
#define MARKER_H

#include <QGraphicsItemGroup>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>

class Marker : public QGraphicsItemGroup
{
    Q_OBJECT
public:
    Marker();

private:
    QGraphicsEllipseItem *m_ellipse = new QGraphicsEllipseItem();
    QGraphicsTextItem *m_text = new QGraphicsTextItem();
};

#endif // MARKER_H
