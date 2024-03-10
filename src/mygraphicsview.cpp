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
    this->fitInView(m_img, Qt::KeepAspectRatio);
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
