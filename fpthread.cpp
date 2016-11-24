#include "fpthread.h"

FPThread::FPThread(QObject* parent): QThread(parent)
{
    for (int i = 0; i < 20; i++)
    {
        QVector<int> a;
        for (int j = 0; j < 20; j++)
        {
            a.push_back(0);
        }
        map.push_back(a);
    }

    for(int i = 0; i < 20; i++)
    {
        map[i][0] = map[0][i] = map[19][i] = map[i][19] = -1;
    }
}


void FPThread :: run()
{

}
