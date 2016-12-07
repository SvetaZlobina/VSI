#include "printdialog.h"
#include "ui_printdialog.h"

PrintDialog::PrintDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrintDialog)
{
    ui->setupUi(this);


    th = new MyThread();
    connect(th, SIGNAL(NumberChanged()), this, SLOT(onNumberChanged()));
    th->start();

}

void PrintDialog::onNumberChanged()
{
    drawFlag = true;
    update();
}

void PrintDialog :: paintEvent(QPaintEvent* e)
 {
     if(drawFlag)
     {
         QPainter painter(this);
         QPen pen,pen2;


         QPoint p1;
         QPoint p2;

         QBrush brush;
         brush.setStyle(Qt::SolidPattern);
         int count = 2;

         painter.setBrush(brush);

         for(int i = 0; i < th->arr.size(); i++)
         {
             if(i == th->ind1 || i == th->ind2)
             {
                 brush.setColor(Qt :: green);
                 brush.setStyle(Qt :: SolidPattern);
                 painter.setBrush(brush);
                // pen.setColor("#ffa800");
                // painter.setPen(pen);
             }
             else
             {
                 brush.setColor(Qt::lightGray);
                 painter.setBrush(brush);
                // pen.setColor("#792500");
                // painter.setPen(pen);
             }
            painter.drawRect(count*120+i*4,500-th->arr[i]*10, 4, th->arr[i]*10);

            // painter.drawLine(i,500-th->arr[i]*8, i, 500  );

         }

         ui->label->setText("Swaps:  " + QString :: number(th->swaps));
         drawFlag = false;
     }
}

PrintDialog::~PrintDialog()
{
    delete ui;
}
