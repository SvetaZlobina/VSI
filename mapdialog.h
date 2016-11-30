#ifndef MAPDIALOD_H
#define MAPDIALOD_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include "fpthread.h"
#include <QVector>
#include <QDebug>
#include <QMessageBox>
#include <QMouseEvent>

namespace Ui {
class MapDialog;
}

class MapDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MapDialog(QWidget *parent = 0);
    ~MapDialog();

    bool drawFlag = false;
    void mouseReleaseEvent ( QMouseEvent * event );

    FPThread* fp;

protected:
    void paintEvent(QPaintEvent* e);

private:
    Ui::MapDialog *ui;

public slots:
    void onNumberChanged();
};

#endif // MAPDIALOD_H
