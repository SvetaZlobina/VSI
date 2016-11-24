#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QVector>


class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject* parebt = 0);
    void run();
    bool Stop = false;

    void heapify(QVector<double>& arr, int n, int i);
    void heapSort(QVector<double>& arr, int n);
    void insertionSort(QVector<double> arr);
    void quickSort(QVector<double>& arr, int l, int r);
    void shellSort( QVector <double>& arr);

    int sortNumber = 2;
    QVector<double> arr;
    int ind1, ind2;

    QVector< QVector<int> > map;


signals:
    void NumberChanged();

};

#endif // MYTHREAD_H
