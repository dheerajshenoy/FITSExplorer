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
    inline QString getPlainText() { return m_text->toPlainText(); }
    inline QGraphicsEllipseItem* getEllipse() {
        return m_ellipse;
    }

    void setShapeColor(QColor color);
    void setShape(QGraphicsItem*);
    void setText(QString);
    void setTextColor(QColor color);
    void setTextItem(QGraphicsTextItem*);
    void addVisualizer();

private:
    QGraphicsEllipseItem *m_ellipse;
    QGraphicsTextItem *m_text;
    QString m_id;
};

#endif // MARKER_H
