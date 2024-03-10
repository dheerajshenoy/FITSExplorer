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

void MyGraphicsView::mouseMoveEvent(QMouseEvent *e)
{
    QPoint pos = e->pos();
    QPointF scenePos = this->mapToScene(pos);
    QPointF imagePos = m_img->mapFromScene(scenePos);

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
