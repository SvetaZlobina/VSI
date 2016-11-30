#include "dialog.h"
#include "mapdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    w.setFixedSize(700,600);

    MapDialog m;
    m.show();

    qRegisterMetaType<QVector<double>>("QVector<double>");
    return a.exec();
}
