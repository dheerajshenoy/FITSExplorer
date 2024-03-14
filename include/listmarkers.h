#ifndef LISTMARKERS_H
#define LISTMARKERS_H

#include <QWidget>
#include <QVector>
#include "marker.h"

namespace Ui {
class ListMarkers;
}

class ListMarkers : public QWidget
{
    Q_OBJECT

public:
    explicit ListMarkers(QWidget *parent = nullptr);
    ~ListMarkers();

    void setMarkersList(QVector<Marker*>);

signals:
    void markerRemoved(int);

private slots:
    void on_ok_btn_clicked();
    void on_delete_marker_btn_clicked();

    void on_cancel_btn_clicked();

    void on_markers_list_widget_currentTextChanged(const QString &currentText);

private:
    Ui::ListMarkers *ui;
    QVector<Marker*> m_markers_list;
};

#endif // LISTMARKERS_H
