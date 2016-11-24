#ifndef FPTHREAD_H
#define FPTHREAD_H

#include <QThread>
#include <QVector>



class FPThread : public QThread
{
    Q_OBJECT
public:
    explicit FPThread(QObject* parebt = 0);
    void run();
    bool Stop = false;

    QVector< QVector<int> > map;
    int ind1, ind2;

signals:
    void NumberChanged();
};

#endif // FPTHREAD_H
