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
    void mouseMoveEvent ( QMouseEvent * event );
    void mousePressEvent ( QMouseEvent * event );
    void mouseReleaseEvent ( QMouseEvent * event );

    int x, y;
    int cellSize = 12;
    int cellNum = 50;

    FPThread* fp;

protected:
    void paintEvent(QPaintEvent* e);

private:
    Ui::MapDialog *ui;

public slots:
    void onNumberChanged();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // MAPDIALOD_H
