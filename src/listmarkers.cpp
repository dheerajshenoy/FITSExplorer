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

    ui->delete_marker_btn->setEnabled(true);
    ui->text_field->setEnabled(true);
    ui->color_btn->setEnabled(true);
    ui->text_color_btn->setEnabled(true);
}

void ListMarkers::on_ok_btn_clicked()
{
    this->destroy();
}


void ListMarkers::on_delete_marker_btn_clicked()
{
    int markernum = currentMarker();
    ui->markers_list_widget->removeItemWidget(ui->markers_list_widget->currentItem());
    m_markers_list.remove(markernum);
    emit markerRemoved(markernum);
}


void ListMarkers::refreshSelection(int index)
{
    Marker *m = m_markers_list[index];
    ui->text_field->setText(m->getPlainText());
    QColor color = m->getEllipse()->brush().color();
    QPalette palette(ui->color_btn->palette());
    palette.setColor(QPalette::Button, color);
    ui->color_btn->setAutoFillBackground(true);
    ui->color_btn->setPalette(palette);
}


void ListMarkers::on_markers_list_widget_currentTextChanged(const QString &currentText)
{
    refreshSelection(currentMarker());
}

int ListMarkers::currentMarker()
{
    return ui->markers_list_widget->currentIndex().row();
}

void ListMarkers::on_color_btn_clicked()
{

    QColor color = QColorDialog::getColor(Qt::yellow, nullptr, "Select a color for the marker");
    QPalette pal = ui->color_btn->palette();
    pal.setColor(QPalette::Button, color);
    ui->color_btn->setPalette(pal);

    Marker *marker = m_markers_list[currentMarker()];

    marker->setShapeColor(ui->color_btn->palette().color(QPalette::Button));
    marker->setText(ui->text_field->text());

}

