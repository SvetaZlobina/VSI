#include "dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    w.setFixedSize(700,600);


    qRegisterMetaType<QVector<double>>("QVector<double>");
    return a.exec();
}
