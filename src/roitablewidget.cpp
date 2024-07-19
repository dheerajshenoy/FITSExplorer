#include "roitablewidget.h"
#include "ui_roitablewidget.h"

ROITableWidget::ROITableWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ROITableWidget)
{
    ui->setupUi(this);
    ui->table->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
    connect(ui->table, &QTableWidget::customContextMenuRequested, this, &ROITableWidget::showContextMenu);

    ui->table->setHorizontalHeaderLabels({ "ROI ID", "Name"});

    m_menu->addAction(m_delete_action);
    m_menu->addAction(m_hide_action);
    m_menu->addAction(m_show_action);
    m_menu->addAction(m_close_action);
    m_menu->addAction(m_zoom_action);

    connect(m_delete_action, &QAction::triggered, this, &ROITableWidget::handleDelete);
    connect(m_hide_action, &QAction::triggered, this, &ROITableWidget::handleHide);
    connect(m_show_action, &QAction::triggered, this, &ROITableWidget::handleShow);
    connect(m_close_action, &QAction::triggered, this, &ROITableWidget::handleClose);
    connect(m_zoom_action, &QAction::triggered, this, &ROITableWidget::handleZoom);

    // connect(ui->table, &QTableWidget::itemClicked, this, &ROITableWidget::handleSelect);
    connect(ui->table, &QTableWidget::itemSelectionChanged, this, &ROITableWidget::handleSelect);
}

void ROITableWidget::handleDelete()
{
    QList<QTableWidgetItem*> selections = ui->table->selectedItems();

    for (int i=0; i < selections.size(); i += 2)
    {
        emit deleteROI(QUuid::fromString(selections[i]->text()));
        ui->table->removeRow(selections[i]->row());
    }
}

void ROITableWidget::handleHide()
{
    QList<QTableWidgetItem*> selections = ui->table->selectedItems();

    for (int i=0; i < selections.size(); i += 2)
    {
        emit hideROI(QUuid::fromString(selections[i]->text()));
    }
}

void ROITableWidget::handleShow()
{

    QList<QTableWidgetItem*> selections = ui->table->selectedItems();

    for (int i=0; i < selections.size(); i += 2)
    {
        emit showROI(QUuid::fromString(selections[i]->text()));
    }
}

void ROITableWidget::handleClose()
{

}

void ROITableWidget::handleSelect()
{
    QList<QTableWidgetItem*> selections = ui->table->selectedItems();

    for (int i=0; i < selections.size(); i += 2)
    {
        emit selectROI(QUuid::fromString(selections[i]->text()));
    }

    for(int i=0; i < ui->table->rowCount(); i++)
    {
        for(int j=0; j < ui->table->columnCount(); j++)
        {
            QTableWidgetItem *item = ui->table->item(i, j);
            if (item)
            {
                if (selections.contains(item))
                    emit selectROI(QUuid::fromString(item->text()));
                else
                    emit unselectROI(QUuid::fromString(item->text()));
            }
        }
    }
}

void ROITableWidget::handleZoom()
{

    QList<QTableWidgetItem*> selections = ui->table->selectedItems();

    for (int i=0; i < selections.size(); i += 2)
    {
        emit zoomROI(QUuid::fromString(selections[i]->text()));
    }
}


void ROITableWidget::showContextMenu(const QPoint &pos)
{
    QPoint p = mapToGlobal(pos);
    QTableWidgetItem *item = ui->table->item(p.x(), p.y());

    m_menu->exec(p);
}

void ROITableWidget::addItem(QUuid uid, QRectF rect)
{
    QTableWidgetItem *item_uid = new QTableWidgetItem(uid.toString());
    QTableWidgetItem *item_name = new QTableWidgetItem(QString("DD"));

    ui->table->insertRow(ui->table->rowCount());

    int row = ui->table->rowCount() - 1;

    ui->table->setItem(row, 0, item_uid);
    ui->table->setItem(row, 1, item_name);
}

ROITableWidget::~ROITableWidget()
{
    delete ui;
}

void ROITableWidget::removeItem(QUuid uid)
{
    for(int i=0; i < ui->table->rowCount(); i++)
    {
        if (ui->table->item(i, 0)->text() == uid.toString())
        {
            ui->table->removeRow(i);
        }
    }
}
