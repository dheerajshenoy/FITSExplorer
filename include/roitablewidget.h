#ifndef ROITABLEWIDGET_H
#define ROITABLEWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QUuid>
#include <QMenu>

namespace Ui {
class ROITableWidget;
}

class ROITableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ROITableWidget(QWidget *parent = nullptr);
    ~ROITableWidget();

    void addItem(QUuid, QRectF);
    void removeItem(QUuid);

signals:
    void deleteROI(QUuid uid);

private:
    Ui::ROITableWidget *ui;
    void showContextMenu(const QPoint &pos);

    void handleHide();
    void handleClose();
    void handleZoom();
    void handleDelete();

    QAction *m_delete_action = new QAction("Delete");
    QAction * m_hide_action = new QAction("Hide");
    QAction *m_close_action = new QAction("Close");
    QAction* m_zoom_action = new QAction("Zoom");
    QMenu *m_menu = new QMenu(this);
};

#endif // ROITABLEWIDGET_H
