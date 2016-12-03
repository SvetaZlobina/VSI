#ifndef FPTHREAD_H
#define FPTHREAD_H

#include <QThread>
#include <QVector>
#include <QDebug>



class FPThread : public QThread
{
    Q_OBJECT
public:
    explicit FPThread(QObject* parebt = 0);
    void run();
    bool Stop = false;

    QVector<QVector<int>> map;
    QVector<QPair<int,int>> path;
    int ind1, ind2;

    QPair<int, int> st, end;

    //void work();
    bool finding = false;



signals:
    void NumberChanged();
};

#endif // FPTHREAD_H
