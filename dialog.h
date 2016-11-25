#ifndef DIALOG_H
#define DIALOG_H

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

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // DIALOG_H
