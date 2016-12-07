#ifndef PRINTDIALOG_H
#define PRINTDIALOG_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include "mythread.h"
#include "fpthread.h"
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QDebug>
#include <QMessageBox>
#include <QMouseEvent>


namespace Ui {
class PrintDialog;
}

class PrintDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PrintDialog(QWidget *parent = 0);
    ~PrintDialog();
    MyThread* th;
    FPThread* fp;
    bool drawFlag = false;

protected:
    void paintEvent(QPaintEvent* e);

public slots:
    void onNumberChanged();


private:
    Ui::PrintDialog *ui;
};

#endif // PRINTDIALOG_H
