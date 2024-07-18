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
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QRgb>
#include <QShortcut>
#include <QKeySequence>
#include "roirect.h"
#include <QUuid>
#include <QMap>
#include "pixanalyser.h"
#include <QGraphicsProxyWidget>

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
    void setPixelAnalysisMode(bool);
    void ZoomIntoROI(QUuid uid);
    void ZoomIntoLastROI();
    void AddROIRect(ROIRect*);
    void DeleteROIRect(QUuid uid);
    void DeleteROIRect__for_table(QUuid uid);
    void HideROIRect(QUuid uid);
    void HideROIRect__for_table(QUuid uid);
    int GetROIIndex();
    ROIRect* GetROIRect(QUuid uid);
    PixAnalyser* getPixAnalyser();
    void movePixAnalyser(QPoint);
    void setPixValue(float);
    void SelectROI(QUuid uid);
    void UnselectROI(QUuid uid);

signals:
    void mouseMoved(QPointF);
    void mouseOutsidePixmap();
    void markerAdded(QPointF);
    void markersRemoved();
    void viewportChanged();
    void markerColorChanged(int, QColor);
    void markersHidden(bool);
    void newROIRect(QUuid, QRectF);
    void signalROITable(QUuid);
    void pixelAnalysisRequested(QPoint);

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

    QShortcut *kb_zoom_in, *kb_zoom_out, *kb_roi_zoom;
    void initShortcuts();
    int m_roi_index = -1;
    QPixmap m_pix;
    QGraphicsScene *m_scene = new QGraphicsScene();
    QGraphicsPixmapItem *m_img;
    bool m_markerMode = false;
    bool m_select_mode = false;
    bool m_pix_analysis_mode = false;
    ListMarkers* lm = new ListMarkers();
    QVector<Marker*> m_markerList;
    QRubberBand *m_rubberband = nullptr;
    QPoint m_roi_start_pos, m_roi_end_pos;
    QMap<QUuid , ROIRect*> m_roi_map;

    PixAnalyser *m_pix_analyser = nullptr;
};

#endif
