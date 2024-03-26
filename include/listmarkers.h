#ifndef LISTMARKERS_H
#define LISTMARKERS_H

#include <QWidget>
#include <QVector>
#include "marker.h"
#include <QColorDialog>

namespace Ui {
class ListMarkers;
}

class ListMarkers : public QWidget
{
    Q_OBJECT

public:
    explicit ListMarkers(QWidget *parent = nullptr);
    ~ListMarkers();

    void setMarkersList(const QVector<Marker*>&);
    void refreshSelection(int index);

    int currentMarker();
    int getMarkerCount();
    void clearMarkerList();
signals:
    void markerRemoved(int);
    void markerColorChanged(int, QColor);

private slots:
    void on_ok_btn_clicked();
    void on_delete_marker_btn_clicked();
    void on_markers_list_widget_currentTextChanged(const QString &currentText);

    void updateMarkerText();
    void on_color_btn_clicked();


private:
    Ui::ListMarkers *ui;
    QVector<Marker*> m_markers_list;
};

#endif // LISTMARKERS_H
