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

    void changeBorderColor(QColor);
    void revertBorderColor();
    void changeBorderWidth(int);
    void setName(QString name) { m_name = name; }
    void setTextItem(QGraphicsTextItem *item);
    QGraphicsTextItem* getTextItem() { return m_text_item; }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent* event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

signals:
    void deleteItem(QUuid uid);
    void hideItem(QUuid uid);
    void zoomItem(QUuid uid);

private:
    QMenu *contextMenu;
    QString m_name = "Some Text";
    QPen m_border_pen;
    QGraphicsTextItem *m_text_item = nullptr;
    QUuid m_uid;
};

#endif // ROIRECT_H
