#include "listmarkers.h"
#include "ui_listmarkers.h"

ListMarkers::ListMarkers(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListMarkers)
{
    ui->setupUi(this);
}

ListMarkers::~ListMarkers()
{
    delete ui;
}

void ListMarkers::setMarkersList(QVector<Marker *> markers)
{
    m_markers_list = markers;

    foreach(Marker* marker, markers)
    {
        ui->markers_list_widget->addItem(marker->getID());
    }
    this->show();
}

void ListMarkers::on_ok_btn_clicked()
{
    int markernum = ui->markers_list_widget->currentItem()->text().toInt();
    Marker *marker = m_markers_list[markernum];

    //marker->setShapeColor(ui->color_field->text());
    marker->setShapeColor(Qt::yellow);
    marker->setText(ui->text_field->text());
}


void ListMarkers::on_delete_marker_btn_clicked()
{
    int markernum = ui->markers_list_widget->currentItem()->text().toInt();
    ui->markers_list_widget->removeItemWidget(ui->markers_list_widget->currentItem());
    m_markers_list.remove(markernum);
    emit markerRemoved(markernum);
}

