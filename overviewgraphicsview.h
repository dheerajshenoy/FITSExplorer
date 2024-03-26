#ifndef OVERVIEWGRAPHICSVIEW_H
#define OVERVIEWGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>

class OverviewGraphicsView : public QGraphicsView {

public:
    OverviewGraphicsView(QGraphicsScene* scene,
                         QGraphicsView* mainView,
                         QWidget* parent = nullptr);

    inline void updateRect(const QRectF& rect) {
        zoomRect = rect;
        scene()->update();
    }

    inline void setPixmap(QPixmap pix)
    {
        m_scene->addPixmap(pix);
    }

protected:
    void drawForeground(QPainter* painter, const QRectF& rect) override {
        QGraphicsView::drawForeground(painter, rect);
        painter->setPen(Qt::red);
        painter->drawRect(mapFromScene(zoomRect).boundingRect());
    }

private:
    QRectF zoomRect;
    QGraphicsView* m_mainView;
    QGraphicsScene *m_scene = new QGraphicsScene();
};
#endif // OVERVIEWGRAPHICSVIEW_H
