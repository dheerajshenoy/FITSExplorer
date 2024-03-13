#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    this->setScene(m_scene);

    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    this->setDragMode(QGraphicsView::ScrollHandDrag);

    m_img = m_scene->addPixmap(m_pix);

    connect(lm, SIGNAL(markerRemoved(int)), SLOT(removeMarkerAtPos(int)));
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

void MyGraphicsView::fitToWidth(qreal width)
{
    auto imgwidth = m_img->pixmap().width();
    scale(this->width() / imgwidth, this->height() / m_img->pixmap().height());
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *e)
{
    QPointF imagePos = GetCursorPositionInPixmap(e->pos());

    // Get the coordinates only when the cursor is within the pixmap
    if (m_img->pixmap().rect().contains(imagePos.toPoint()))
    {
        emit mouseMoved(imagePos);
    }
    else {
        emit mouseOutsidePixmap();
    }
    QGraphicsView::mouseMoveEvent(e);
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

                QGraphicsTextItem *text = new QGraphicsTextItem("Ellipse");
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
}

void MyGraphicsView::setMarkerMode(bool state)
{
    m_markerMode = state;
}

void MyGraphicsView::listMarkers()
{
    lm->setMarkersList(m_markerList);
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
