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
    m_menu->addAction(m_close_action);
    m_menu->addAction(m_zoom_action);

    connect(m_delete_action, &QAction::triggered, this, &ROITableWidget::handleDelete);
    connect(m_hide_action, &QAction::triggered, this, &ROITableWidget::handleHide);
    connect(m_close_action, &QAction::triggered, this, &ROITableWidget::handleClose);
    connect(m_zoom_action, &QAction::triggered, this, &ROITableWidget::handleZoom);

}

void ROITableWidget::handleDelete()
{
    QList<QTableWidgetItem*> selections = ui->table->selectedItems();

    if (selections.size() == 2)
    {
        emit deleteROI(QUuid::fromString(selections[0]->text()));
        ui->table->removeRow(selections[0]->row());
    }
    else if (selections.size() > 2)
    {
    }
}

void ROITableWidget::handleHide()
{

}

void ROITableWidget::handleClose()
{

}

void ROITableWidget::handleZoom()
{

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
    QTableWidgetItem *item_rect = new QTableWidgetItem(QString("DD"));

    ui->table->insertRow(ui->table->rowCount());

    int row = ui->table->rowCount() - 1;

    fprintf(stderr, "%d", row);

    ui->table->setItem(row, 0, item_uid);
    ui->table->setItem(row, 1, item_rect);
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
