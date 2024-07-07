#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QWheelEvent>
#include <QCursor>
#include <QRubberBand>
#include <QMouseEvent>
#include "marker.h"
#include "listmarkers.h"

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    MyGraphicsView(QWidget *parent = nullptr);

    inline QPixmap GetPixmap() { return m_pix; }
    void setPixmap(QPixmap pix);

    QPointF GetCursorPositionInPixmap(QPoint pos);

    void RemoveAllMarkers();
    void HideAllMarkers();
    void fitToWidth(qreal);
    void setMarkerMode(bool);
    void listMarkers();
    void removeMarkerAtPos(int);
    void ZoomIn();
    void ZoomOut();
    void ShowAllMarkers();
    void setSelectMode(bool);

signals:
    void mouseMoved(QPointF);
    void mouseOutsidePixmap();
    void markerAdded(QPointF);
    void markersRemoved();
    void viewportChanged();
    void markerColorChanged(int, QColor);
    void markersHidden(bool);

private slots:
    void __changeMarkerLineColor(int, QColor);

protected:
    virtual void wheelEvent(QWheelEvent *e) override;
    virtual void mouseMoveEvent(QMouseEvent *e) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *e) override;
    virtual void mousePressEvent(QMouseEvent *e) override;
    virtual void mouseReleaseEvent(QMouseEvent *e) override;

    void resizeEvent(QResizeEvent *event) override {
        QGraphicsView::resizeEvent(event);
        emit viewportChanged();
    }

private:
    QPixmap m_pix;
    QGraphicsScene *m_scene = new QGraphicsScene();
    QGraphicsPixmapItem *m_img;
    bool m_markerMode = false;
    ListMarkers* lm = new ListMarkers();
    QVector<Marker*> m_markerList;

    QRubberBand *m_rubberband = nullptr;

    QPoint m_roi_start_pos, m_roi_end_pos;
    bool m_select_mode = false;
};

#endif
