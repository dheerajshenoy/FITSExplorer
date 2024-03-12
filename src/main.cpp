#include "FITSExplorer.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FITSExplorer w(QApplication::arguments());
    w.show();
    return a.exec();
}
