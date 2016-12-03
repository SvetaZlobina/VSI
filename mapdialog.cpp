#include "mapdialog.h"
#include "ui_mapdialog.h"

MapDialog::MapDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapDialog)
{
    ui->setupUi(this);

    fp = new FPThread();
    connect(fp, SIGNAL(NumberChanged()), this, SLOT(onNumberChanged()));
    fp->start();
}

MapDialog::~MapDialog()
{
    delete ui;
}

void MapDialog::onNumberChanged()
{
    drawFlag = true;
    update();
}


bool draw;

void MapDialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && event->pos().x() < cellNum*cellSize && event->pos().y() < cellNum*cellSize)
    {
        x = event->pos().x()/10;
        y = event->pos().y()/10;

        if(fp->map[x][y] == 9999) fp->map[x][y] = -1;
        else fp->map[x][y] = 9999;

        draw = true;
    }
}

void MapDialog :: mouseMoveEvent ( QMouseEvent * event )
{
    //qDebug() << event->pos().x();
    if(event->buttons() == Qt::LeftButton)
    {
        if(event->pos().x()/10 != x || event->pos().y()/10 != y)
        {
            x = event->pos().x()/10;
            y = event->pos().y()/10;
            if(fp->map[x][y] == 9999) fp->map[x][y] = -1;
            else fp->map[x][y] = 9999;
        }


    }
}

void MapDialog::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && draw)
    {
        draw = false;
    }
}



void MapDialog :: paintEvent(QPaintEvent* e)
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


         for(int i = 0; i < fp->map.size(); i++)
         {
             for(int j = 0; j < fp->map[i].size(); j++)
             {
                 if(fp->map[i][j] == 9999)
                 {
                     brush.setColor(Qt :: black);
                     painter.setBrush(brush);
                     painter.drawRect(i*10,j*10,10,10);
                 }
                 else if(fp->map[i][j] != 9999 && fp->map[i][j] != -1)
                 {
                     brush.setColor(Qt :: green);
                     painter.setBrush(brush);
                     painter.drawRect(i*10,j*10,10,10);
                 }
             }
         }

         for(int i = 0; i < fp->path.size(); i++)
         {

             brush.setColor(Qt :: red);
             painter.setBrush(brush);
             painter.drawRect(fp->path[i].first*10,fp->path[i].second*10,10,10);
         }

     }
}

void MapDialog::on_pushButton_clicked()
{
    fp->finding = true;
}
