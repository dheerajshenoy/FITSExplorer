#ifndef MARKER_H
#define MARKER_H

#include <QGraphicsItemGroup>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QColor>

class Marker : public QGraphicsItemGroup
{
public:
    Marker(QGraphicsItem *parent = nullptr);

    void setMarker(QGraphicsEllipseItem* ellipse = nullptr,
                    QGraphicsTextItem* text = nullptr,
                    QString id = nullptr);
    inline QString getID() { return m_id; }

    void setShapeColor(QColor color);
    void setShape(QGraphicsItem*);
    void setText(QString);
    void setTextItem(QGraphicsTextItem*);

private:
    QGraphicsEllipseItem *m_ellipse;
    QGraphicsTextItem *m_text;
    QString m_id;
};

#endif // MARKER_H
