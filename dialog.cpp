#include "dialog.h"
#include "ui_dialog.h"
#include <printdialog.h>



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    th = new MyThread();
    connect(th, SIGNAL(NumberChanged()), this, SLOT(onNumberChanged()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onNumberChanged()
{
    drawFlag = true;
    update();
}

void Dialog :: paintEvent(QPaintEvent* e)
 {
     if(drawFlag)
     {
         QPainter painter(this);
         QPen pen;

         QPoint p1;
         QPoint p2;

         QBrush brush;
         //brush.setStyle(Qt::SolidPattern);

         int count = 2;

         painter.setBrush(brush);

         for(int i = 0; i < th->arr.size(); i++)
         {
             if(i == th->ind1 || i == th->ind2)
             {
                 brush.setColor(Qt :: green);
                 brush.setStyle(Qt :: SolidPattern);
                 painter.setBrush(brush);
             }
             else
             {
                 brush.setColor(Qt::lightGray);
                 painter.setBrush(brush);
             }
            painter.drawRect(count*120+i*2,500-th->arr[i]*10, 2, th->arr[i]*10);
         }

         drawFlag = false;
     }

}

void Dialog::on_pushButton_clicked()
{

    th->arr.clear();

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
    th->Stop = true;
}

void Dialog::on_pushButton_3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
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
    file.close();
}
