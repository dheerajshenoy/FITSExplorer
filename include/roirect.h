#ifndef ROIRECT_H
#define ROIRECT_H

#include <QGraphicsRectItem>
#include <QMenu>
#include <QAction>
#include <QObject>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QUuid>

class ROIRect : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    explicit ROIRect(QRectF &rect);

    QUuid uid() { return m_uid; }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent* event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;

signals:
    void deleteItem(QUuid uid);
    void hideItem(QUuid uid);
    void zoomItem(QUuid uid);

private:
    QMenu *contextMenu;

    QUuid m_uid;
};

#endif // ROIRECT_H
