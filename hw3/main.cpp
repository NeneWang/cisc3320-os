#include <iostream>
#include <mutex>
#include <thread>
#include <cstdio>
#include <unistd.h>

using namespace std;

long sum = 0;
mutex m;

void populateNumbers(int range, int *array)
{
    for (int i = 1; i <= range; i++)
    {
        array[i - 1] = i;
    }
}

void sumAll(int range, int start, int arrayNums[])
{

    for (int i = start; i < range; i++)
    {
        m.lock();
        int temp = sum + arrayNums[i];
        usleep(1);
        sum = temp;
        m.unlock();
        // cout << "THREAD" << range<< endl;
    }
}

int main()
{
    const int SIZE = 1000, SPLITS = 5, FRAMESIZE = SIZE / (SPLITS);
    int populatedArr[SIZE];
    thread threads[SPLITS];

    populateNumbers(SIZE, populatedArr);
    for (int i = 0; i < SPLITS; i++)
    {
        int rangeMax = FRAMESIZE * (i + 1), rangeMin = rangeMax - FRAMESIZE;
        threads[i] = thread(sumAll, rangeMax, rangeMin, populatedArr);
    }

    for (int i = 0; i < SPLITS; i++)
    {
        threads[i].join();
    }

    cout << sum << endl;
}
