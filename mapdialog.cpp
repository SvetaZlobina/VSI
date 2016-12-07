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


bool draw, del;

void MapDialog::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && event->pos().x() < cellNum*cellSize && event->pos().y() < cellNum*cellSize)
    {
        x = event->pos().x()/cellSize;
        y = event->pos().y()/cellSize;

        if(fp->map[x][y] == 9999 && fp->map[x][y] != 0)
        {
            fp->map[x][y] = -1;
            del = true;
        }
        else if (fp->map[x][y] != 0)
        {
            fp->map[x][y] = 9999;
            del = false;
        }

        draw = true;
    }
}

void MapDialog :: mouseMoveEvent ( QMouseEvent * event )
{
    //qDebug() << event->pos().x();
    if(event->buttons() == Qt::LeftButton && draw && event->pos().x() < cellNum*cellSize && event->pos().y() < cellNum*cellSize)
    {
        if(event->pos().x()/cellSize != x || event->pos().y()/cellSize != y)
        {
            x = event->pos().x()/cellSize;
            y = event->pos().y()/cellSize;
            if(fp->map[x][y] == 9999 && del && fp->map[x][y] != 0) fp->map[x][y] = -1;
            else if(!del && fp->map[x][y] != 0) fp->map[x][y] = 9999;
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
                     painter.drawRect(i*cellSize,j*cellSize,cellSize,cellSize);
                 }
                 else if(fp->map[i][j] != 9999 && fp->map[i][j] != -1)
                 {
                     brush.setColor(Qt :: green);
                     painter.setBrush(brush);
                     painter.drawRect(i*cellSize,j*cellSize,cellSize,cellSize);
                 }
             }
         }

         for(int i = 0; i < fp->path.size(); i++)
         {

             brush.setColor(Qt :: red);
             painter.setBrush(brush);
             painter.drawRect(fp->path[i].first*cellSize,fp->path[i].second*cellSize,cellSize,cellSize);
         }

     }
}

void MapDialog::on_pushButton_clicked()
{
    fp->finding = true;
}

void MapDialog::on_pushButton_2_clicked()
{
    int N = fp->map.size();
    for (int i = 0; i < N; ++i)
    {
        fp->map[i][0] = 9999;
        fp->map[0][i] = 9999;
        fp->map[i][N - 1] = 9999;
        fp->map[N - 1][i] = 9999;
    }

    for(int i = 1; i < N-1; i++)
    {
        for (int j = 1; j < N-1; j++)
        {
            fp->map[i][j] = -1;
        }

        fp->map[1][1] = 0;
    }

    fp->path.clear();
}
