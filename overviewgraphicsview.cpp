#include "overviewgraphicsview.h"


OverviewGraphicsView::OverviewGraphicsView(QGraphicsScene* scene,
                                           QGraphicsView* mainView,
                                           QWidget* parent)
{
    this->setScene(m_scene);
}

