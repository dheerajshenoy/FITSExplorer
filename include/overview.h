#ifndef OVERVIEW_H
#define OVERVIEW_H

#include <QWidget>
#include <QVector>
#include <QString>
#include <QMap>

namespace Ui {
class Overview;
}

class Overview : public QWidget
{
    Q_OBJECT

public:
    explicit Overview(QWidget *parent = nullptr);
    ~Overview();

    void SetRecords(QMap<QString, QString>);
    QVector<QString> getRecords();
    inline bool hasBeenAlreadyShown() { return shownAlready; }

private slots:
    void on_rawBtn_clicked();

private:
    Ui::Overview *ui;
    bool shownAlready = false;
    QVector<QString> m_records;
};

#endif // OVERVIEW_H
