#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QWidget>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QWidget
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = nullptr);
    ~AboutDialog();

private slots:

    void on_gitBtn_clicked();
    void on_linkedinBtn_clicked();

private:
    Ui::AboutDialog *ui;
};

#endif // ABOUTDIALOG_H
