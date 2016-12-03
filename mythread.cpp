#include "mythread.h"
#include <QtCore>

MyThread::MyThread(QObject* parent): QThread(parent)
{}

int sleepTime = 50;

template<class T>
void MyThread :: Swap(T& a, T& b, int i1, int i2)
{
    qSwap(a, b);
    swaps++;
    ind1 = i1;
    ind2 = i2;
    emit NumberChanged();
    msleep(sleepTime);
}

void MyThread :: quickSort(QVector<double>& arr, int l, int r)
{
    int x = arr[l + (r - l) / 2];
    int i = l;
    int j = r;
    while(i <= j)
    {
        while(arr[i] < x) i++;
        while(arr[j] > x) j--;
        if(i <= j)
        {
            Swap(arr[i], arr[j], i, j);

            i++;
            j--;
        }
    }
    if (i<r)
        quickSort(arr, i, r);

    if (l<j)
        quickSort(arr, l, j);
}



void MyThread :: shellSort( QVector <double>& arr)
{
     int i, flag = 1;
     int d = arr.size();
     while( flag || (d > 1))      // boolean flag (true when not equal to 0)
     {
          flag = 0;           // reset flag to 0 to check for future swaps
          d = (d+1) / 2;
          for (i = 0; i < (arr.size() - d); i++)
        {
               if (arr[i + d] < arr[i])
              {
                   Swap(arr[i], arr[i+d], i, i+d);
                   flag = 1;
              }
         }
     }
}


void MyThread :: insertionSort(QVector<double> arr)
{
     int i, j;
     for (i = 1; i < arr.size(); i++)
     {
         j = i;
         while (j > 0 && arr[j - 1] > arr[j])
         {
             Swap(arr[j], arr[j-1], j, j-1);
             j--;
         }
     }
}

void MyThread :: heapify(QVector<double>& arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        Swap(arr[i], arr[largest], i, largest);
        heapify(arr, n, largest);
    }
}

void MyThread :: heapSort(QVector<double>& arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        Swap(arr[0], arr[i], 0, i);
        heapify(arr, i, 0);
    }
}


void MyThread :: run()
{

    for(int i = 0; i < 150; ++i)
        arr.push_back(qrand() % 50);

    switch (sortNumber)
    {
        case 0:
            heapSort(arr, arr.size());
            break;
        case 1:
            shellSort(arr);
            break;
        case 2:
            quickSort(arr, 0, arr.size()-1);
            break;
        default:
            break;
    }
}



