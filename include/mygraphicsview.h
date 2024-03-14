#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QWheelEvent>
#include "marker.h"
#include "listmarkers.h"
#include <QCursor>

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    MyGraphicsView(QWidget *parent = nullptr);

    inline QPixmap GetPixmap() { return m_pix; }
    void setPixmap(QPixmap pix);

    QPointF GetCursorPositionInPixmap(QPoint pos);

    void RemoveAllMarkers();
    void fitToWidth(qreal);
    void setMarkerMode(bool);
    void listMarkers();
    void removeMarkerAtPos(int);
    void ZoomIn();
    void ZoomOut();

signals:
    void mouseMoved(QPointF);
    void mouseOutsidePixmap();
    void markerAdded(QPointF);
    void markersRemoved();

protected:
    virtual void wheelEvent(QWheelEvent *e) override;
    virtual void mouseMoveEvent(QMouseEvent *e) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *e) override;
    virtual void mousePressEvent(QMouseEvent *e) override;

private:
    QPixmap m_pix;
    QGraphicsScene *m_scene = new QGraphicsScene();
    QGraphicsPixmapItem *m_img;
    bool m_markerMode = false;
    ListMarkers* lm = new ListMarkers();
    QVector<Marker*> m_markerList;
};

#endif
