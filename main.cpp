#include "dfits.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DFits w;
    w.show();
    return a.exec();
}
