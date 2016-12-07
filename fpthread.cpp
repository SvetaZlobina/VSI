#include "fpthread.h"


const int N = 50;
const int WALL = 9999;
QVector< QPair<int, int>> wave;
QVector< QPair <int, int> > oldWave;
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };
int nstep = 0;

int sT = 40;

FPThread::FPThread(QObject* parent): QThread(parent)
{
    for (int i = 0; i < N; i++)
    {
        QVector<int> a;
        for (int j = 0; j < N; j++)
        {
            a.push_back(-1);
        }
        map.push_back(a);
    }


    for (int i = 0; i < N; ++i)
    {
        map[i][0] = WALL;
        map[0][i] = WALL;
        map[i][N - 1] = WALL;
        map[N - 1][i] = WALL;
    }





    st.first = 10;
    st.second = 10;
    end.first = 30;
    end.second = 30;
    map[st.first][st.second] = nstep;
    //map[end.first][end.second] = 19; //any number


    oldWave.push_back(QPair<int, int>(st.first, st.second));
}




void FPThread :: run()
{
    while(1)
    {
        emit NumberChanged();
        msleep(sT);

        if(finding)
        {
            while (oldWave.size() > 0)
            {
                ++nstep;
                wave.clear();
                for (QVector<QPair<int, int> >::iterator i = oldWave.begin(); i != oldWave.end(); ++i)
                {
                    for (int d = 0; d < 4; ++d)
                    {
                        int nx = i -> first + dx[d];
                        int ny = i -> second + dy[d];
                        if (map[nx][ny] == -1)
                        {
                            wave.push_back(QPair<int, int>(nx, ny));
                            map[nx][ny] = nstep;//nstep;

                            if (nx == end.first && ny == end.second)
                            {
                                goto done;
                            }
                        }
                    }
                }
                oldWave = wave;
                emit NumberChanged();
                msleep(sT);
            }
         done:
            int x = end.first;
            int y = end.second;
            wave.clear();
            wave.push_back(QPair<int, int>(x, y));

            while (map[x][y] != 0)
            {
                for (int d = 0; d < 4; ++d)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (map[x][y] - 1 == map[nx][ny])
                    {
                        x = nx;
                        y = ny;
                        path.push_back(QPair<int, int>(x, y));
                        break;
                    }
                }
            }
            finding = false;
        }

    }
}
