#include "roirect.h"


ROIRect::ROIRect(QRectF &rect)
    : QGraphicsRectItem(rect)
{
    contextMenu = new QMenu();
    this->setAcceptHoverEvents(true);
    m_border_pen = QPen(Qt::red, 2, Qt::DashLine);
    this->setPen(m_border_pen);
    this->setBrush(QBrush(QColor(255, 255, 255, 50)));

    m_uid = QUuid::createUuid();

    QAction* deleteAction = contextMenu->addAction("Delete");
    QAction* hideAction = contextMenu->addAction("Hide");
    QAction* zoomAction = contextMenu->addAction("Zoom");

    connect(deleteAction, &QAction::triggered, this, [&]() {
        emit deleteItem(m_uid);
    });
    connect(hideAction, &QAction::triggered, this, [&]() {
        emit hideItem(m_uid);
    });

    connect(zoomAction, &QAction::triggered, this, [&]() {
        emit zoomItem(m_uid);
    });
}

void ROIRect::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if (event->button() == Qt::RightButton) {
        event->accept();
        contextMenuEvent(reinterpret_cast<QGraphicsSceneContextMenuEvent*>(event));
    } else {
        QGraphicsRectItem::mousePressEvent(event);
    }
}

void ROIRect::contextMenuEvent(QGraphicsSceneContextMenuEvent* event) {
    contextMenu->exec(event->screenPos());
}

void ROIRect::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    // TODO: Display UID or something
}

void ROIRect::changeBorderColor(QColor color)
{
    m_border_pen.setColor(color);
    this->setPen(m_border_pen);
}

void ROIRect::revertBorderColor()
{
    m_border_pen.setColor(Qt::red);
    this->setPen(m_border_pen);
}
