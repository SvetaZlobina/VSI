#include "dialog.h"
#include "ui_dialog.h"
#include <printdialog.h>



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}





void Dialog::on_pushButton_clicked()
{

    if(ui->radioButton->isChecked())
    {
        PrintDialog* d = new PrintDialog();
        d->th->sortNumber = 0;
        d->show();

    }
    else if(ui->radioButton_2->isChecked())
    {
        PrintDialog* d = new PrintDialog();
        d->th->sortNumber = 1;
        d->show();
    }
    else if(ui->radioButton_3->isChecked())
    {
        PrintDialog* d = new PrintDialog();
        d->th->sortNumber = 2;
        d->show();
    }

    else
        return;
}

void Dialog::on_pushButton_2_clicked()
{
    //th->Stop = true;
}

void Dialog::on_pushButton_3_clicked()
{
    /*QString fileName = QFileDialog::getOpenFileName(this,
             tr("Open File 1"), "/home", tr("JSON Files (*.json)"));
    QFile file(fileName);

    if(file.open(QIODevice::ReadOnly))
        {
            QJsonParseError  parseError;
            QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll(), &parseError);
            if(parseError.error == QJsonParseError::NoError)
            {
                if(jsonDoc.isObject())
                {
                    QJsonArray jArr = jsonDoc.object().value("Array").toArray();
                    foreach (QJsonValue v, jArr)
                    {
                        th->arr.push_back(v.toInt());
                    }

                }
            }else
            {
                qDebug()<<parseError.errorString();
            }

        }else
        {
            qDebug()<<"json.txt not open";
        }


    qDebug() << th->arr.size();
    file.close();*/
}
