#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    this->setScene(m_scene);
    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    this->setDragMode(QGraphicsView::ScrollHandDrag);
    // this->setDragMode(QGraphicsView::RubberBandDrag);

    m_img = m_scene->addPixmap(m_pix);

    connect(lm, SIGNAL(markerRemoved(int)), SLOT(removeMarkerAtPos(int)));
    connect(lm, SIGNAL(markerColorChanged(int, QColor)), SLOT(__changeMarkerLineColor(int, QColor)));

    initShortcuts();
}

void MyGraphicsView::setPixmap(QPixmap pix)
{
    m_pix = pix;
    m_img->setPixmap(m_pix);
    //this->fitInView(m_img, Qt::KeepAspectRatio);
}

QPointF MyGraphicsView::GetCursorPositionInPixmap(QPoint pos)
{
    QPointF scenePos = this->mapToScene(pos);
    return m_img->mapFromScene(scenePos);
}

void MyGraphicsView::RemoveAllMarkers()
{
    if(m_markerList.isEmpty())
        return;

    foreach(Marker* marker, m_markerList)
    {
        m_scene->removeItem(marker);
    }

    m_markerList.clear();

    emit markersRemoved();
}

void MyGraphicsView::HideAllMarkers()
{
    if(m_markerList.isEmpty())
        return;

    foreach(Marker* marker, m_markerList)
    {
        marker->hide();
    }

    emit markersHidden(true);
}

void MyGraphicsView::ShowAllMarkers()
{
    if(m_markerList.isEmpty())
        return;

    foreach(Marker* marker, m_markerList)
    {
        marker->show();
    }

    emit markersHidden(false);
}

void MyGraphicsView::movePixAnalyser(QPoint loc)
{
    if (m_pix_analyser)
        m_pix_analyser->move(loc);
}

void MyGraphicsView::setPixValue(float val)
{
    if (m_pix_analyser)
        m_pix_analyser->setPixValue(val);
}


void MyGraphicsView::fitToWidth(qreal width)
{
    auto imgwidth = m_img->pixmap().width();
    scale(this->width() / imgwidth, this->height() / m_img->pixmap().height());
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *e)
{

    if (m_select_mode && m_rubberband)
    {
        m_rubberband->setGeometry(QRect(m_roi_start_pos, e->pos()).normalized());
    }

    QPointF imagePos = GetCursorPositionInPixmap(e->pos());

    // Get the coordinates only when the cursor is within the pixmap
    if (m_img->pixmap().rect().contains(imagePos.toPoint()))
    {
        emit mouseMoved(imagePos);
        if (m_pix_analysis_mode)
        {
            emit pixelAnalysisRequested(e->pos());
        }
    }
    else {
        emit mouseOutsidePixmap();
    }

    emit viewportChanged();

    QGraphicsView::mouseMoveEvent(e);
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent *e)
{
    if (m_select_mode && m_rubberband)
    {

        m_roi_end_pos = e->pos();
        m_rubberband->hide();

        QRectF boundingrect = mapToScene(m_rubberband->geometry()).boundingRect();
        ROIRect* m_roi_rect = new ROIRect(boundingrect);
        AddROIRect(m_roi_rect);

    }

    QGraphicsView::mouseReleaseEvent(e);
}

void MyGraphicsView::AddROIRect(ROIRect* rect)
{
    m_roi_map[rect->uid()] = rect;

    emit newROIRect(rect->uid(), rect->boundingRect());

    connect(rect, &ROIRect::deleteItem, this, &MyGraphicsView::DeleteROIRect);
    connect(rect, &ROIRect::hideItem, this, &MyGraphicsView::HideROIRect);
    connect(rect, &ROIRect::zoomItem, this, &MyGraphicsView::ZoomIntoROI);
    scene()->addItem(rect);
    scene()->addItem(rect->getTextItem());
}

void MyGraphicsView::DeleteROIRect__for_table(QUuid uid)
{
    ROIRect* rect = m_roi_map[uid];
    scene()->removeItem(rect);
    m_roi_map.remove(uid);
}

void MyGraphicsView::HideROIRect__for_table(QUuid uid)
{
    m_roi_map[uid]->setVisible(false);
}

void MyGraphicsView::ShowROIRect__for_table(QUuid uid)
{
    m_roi_map[uid]->setVisible(true);
}

void MyGraphicsView::DeleteROIRect(QUuid uid)
{
    ROIRect* rect = m_roi_map[uid];
    scene()->removeItem(rect);
    m_roi_map.remove(uid);
    emit signalROITable(uid);
}

int MyGraphicsView::GetROIIndex()
{
    return m_roi_index;
}

ROIRect* MyGraphicsView::GetROIRect(QUuid uid)
{
    return m_roi_map[uid];
}

void MyGraphicsView::HideROIRect(QUuid uid)
{
    m_roi_map[uid]->setVisible(false);
}

void MyGraphicsView::ShowROIRect(QUuid uid)
{
    m_roi_map[uid]->setVisible(true);
}

void MyGraphicsView::ZoomIntoLastROI()
{
    if (m_roi_map.empty()) return;

    ZoomIntoROI(m_roi_map.lastKey());
}

void MyGraphicsView::ZoomIntoROI(QUuid uid)
{

    ROIRect* rect = m_roi_map[uid];
    if (rect)
    {
        QRectF boundingrect = rect->boundingRect();
        this->fitInView(boundingrect, Qt::KeepAspectRatio);
        centerOn(boundingrect.center());
    }
}

void MyGraphicsView::SelectROI(QUuid uid)
{

    ROIRect* rect = m_roi_map[uid];
    if (rect)
    {
        rect->changeBorderColor(QColor(255, 255, 255));
        rect->changeBorderWidth(4);
    }
}

void MyGraphicsView::UnselectROI(QUuid uid)
{

    ROIRect* rect = m_roi_map[uid];
    if (rect)
    {
        rect->revertBorderColor();
    }
}

void MyGraphicsView::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        // Check if marker mode is on
        if(m_markerMode)
        {
            QPointF imagePos = GetCursorPositionInPixmap(e->pos());

            // Add marker only if cursor is within the image
            if(m_img->pixmap().rect().contains(imagePos.toPoint()))
            {
                QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem(-5, -5, 10, 10);
                ellipse->setPen(QColor::fromRgb(255, 0, 0));
                ellipse->setBrush(QColor::fromRgb(255, 0, 0));
                ellipse->setFlag(QGraphicsEllipseItem::ItemIgnoresTransformations);
                ellipse->setPos(imagePos);

                QGraphicsTextItem *text = new QGraphicsTextItem("Marker " + QString::number(m_markerList.count() + 1));
                text->setDefaultTextColor(Qt::white);
                text->setScale(1.5);
                text->setFlag(QGraphicsTextItem::ItemIgnoresTransformations);
                text->setPos(imagePos);
                // Add the text item to the scene
                Marker *marker = new Marker();
                marker->setMarker(ellipse, text, QString::number(m_markerList.count()));
                m_scene->addItem(marker);
                m_markerList.append(marker);
                emit markerAdded(imagePos);
            }
        }
    }
}

void MyGraphicsView::mousePressEvent(QMouseEvent *e)
{

    if (e->button() == Qt::RightButton) return;


    if (m_select_mode)
    {
        if (e->button() == Qt::MiddleButton)
        {
            // TODO: Handle moving when in select mode
            return;
        }
        this->setDragMode(QGraphicsView::NoDrag);
        if (!m_rubberband)
            m_rubberband = new QRubberBand(QRubberBand::Rectangle, this);

        m_rubberband->show();
        m_rubberband->setGeometry(QRect(e->pos(), QSize()).normalized());
        m_roi_start_pos = e->pos();
    }
    QGraphicsView::mousePressEvent(e);
}

void MyGraphicsView::wheelEvent(QWheelEvent *e)
{
    double scaleFactor = 1.5;

    if(e->angleDelta().y() > 0)
    {
        scale(scaleFactor, scaleFactor);
    }
    else
    {
        scale(1/scaleFactor, 1/scaleFactor);
    }

    emit viewportChanged();
}

void MyGraphicsView::setMarkerMode(bool state)
{
    m_markerMode = state;
}

void MyGraphicsView::listMarkers()
{
    if (lm->getMarkerCount() > 0)
    {
        lm->clearMarkerList();
    }
    lm->setMarkersList(m_markerList);
    lm->show();
}

void MyGraphicsView::removeMarkerAtPos(int index)
{
    m_scene->removeItem(m_markerList[index]);
    m_markerList.remove(index);
    emit markersRemoved();
}

void MyGraphicsView::ZoomIn()
{
    double scaleFactor = 1.5;
    scale(scaleFactor, scaleFactor);
}

void MyGraphicsView::ZoomOut()
{
    double scaleFactor = 1.5;
    scale(1/scaleFactor, 1/scaleFactor);
}

void MyGraphicsView::__changeMarkerLineColor(int index, QColor color)
{
    emit markerColorChanged(index, color);
}

void MyGraphicsView::setSelectMode(bool state)
{
    m_select_mode = state;

    if (!state)
    {
        this->setDragMode(QGraphicsView::ScrollHandDrag);
    }
}

void MyGraphicsView::setPixelAnalysisMode(bool state)
{

    m_pix_analysis_mode = state;
    if (state)
    {
        if (!m_pix_analyser)
        {
            m_pix_analyser = new PixAnalyser(this);
            QGraphicsProxyWidget* pw = scene()->addWidget(m_pix_analyser);
            pw->setZValue(1);
            m_pix_analyser->show();
        }
    }
    else
    {
        if (m_pix_analyser)
        {
            delete m_pix_analyser;
            m_pix_analyser = nullptr;
        }
    }
}

void MyGraphicsView::initShortcuts()
{

    kb_zoom_in = new QShortcut(QKeySequence("="), this);
    kb_zoom_out = new QShortcut(QKeySequence("-"), this);
    kb_roi_zoom = new QShortcut(QKeySequence("z"), this);


    connect(kb_zoom_in, &QShortcut::activated, this, [&]() {
        ZoomIn();
    });

    connect(kb_zoom_out, &QShortcut::activated, this, [&]() {

        ZoomOut();
    });

    connect(kb_roi_zoom, &QShortcut::activated, this, [&]() {
        ZoomIntoLastROI();
    });
}
