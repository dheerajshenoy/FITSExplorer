#include "mygraphicsview.h"

MyGraphicsView::MyGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    this->setScene(m_scene);

    m_img = m_scene->addPixmap(m_pix);
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
    int count = m_scene->items().count();
    if(count == 0)
        return;

    QList<QGraphicsItem*> items = m_scene->items();

    foreach (QGraphicsItem* item, items) {
        if(dynamic_cast<QGraphicsEllipseItem*>(item) || dynamic_cast<QGraphicsTextItem*>(item))
        {
            m_scene->removeItem(item);
            delete item;
        }
    }
    emit markersRemoved();
}

void MyGraphicsView::fitToWidth(qreal width)
{
    // TODO
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
    // Add marker only if cursor is within the image

    if(e->button() == Qt::LeftButton)
    {
        QPointF imagePos = GetCursorPositionInPixmap(e->pos());
        if(m_img->pixmap().rect().contains(imagePos.toPoint()))
        {
            QGraphicsEllipseItem *marker = new QGraphicsEllipseItem(-5, -5, 10, 10);
            marker->setPen(QColor::fromRgb(255, 0, 0));
            marker->setBrush(QColor::fromRgb(255, 0, 0));
            marker->setFlag(QGraphicsEllipseItem::ItemIgnoresTransformations);
            marker->setPos(imagePos);

            QGraphicsTextItem *textItem = new QGraphicsTextItem("Ellipse");
            textItem->setDefaultTextColor(Qt::white);
            textItem->setScale(1.5);
            textItem->setFlag(QGraphicsTextItem::ItemIgnoresTransformations);

            // Position the text item relative to the ellipse
            textItem->setPos(imagePos);

            // Add the text item to the scene
            m_scene->addItem(textItem);
            m_scene->addItem(marker);

            emit markerAdded(imagePos);
        }
    }
}

void MyGraphicsView::wheelEvent(QWheelEvent *e)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setDragMode(QGraphicsView::ScrollHandDrag);
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
