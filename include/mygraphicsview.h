#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QWheelEvent>

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    MyGraphicsView(QWidget *parent = nullptr);

    inline QPixmap GetPixmap() { return m_pix; }
    void setPixmap(QPixmap pix);

signals:
    void mouseMoved(QPointF);

protected:
    virtual void wheelEvent(QWheelEvent *e) override;
    virtual void mouseMoveEvent(QMouseEvent *e) override;
    using QGraphicsView::QGraphicsView;

private:
    QPixmap m_pix;
    QGraphicsScene *m_scene = new QGraphicsScene();
    QGraphicsPixmapItem *m_img;
};

#endif // MYGRAPHICSVIEW_H
