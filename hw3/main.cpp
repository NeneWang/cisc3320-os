#include <iostream>
#include <mutex>
#include <thread>
#include <cstdio>

using namespace std;


long sum = 0;
void populateNumbers(int range, int *array){
    for(int i = 1; i<=range; i++){
        array[i-1] = i;
    }
}

void sumAll(int range, int start, int arrayNums[]){
    
    for(int i = start; i < range; i++){
        sum+=arrayNums[i];
    }
}

int main(){
    const int SIZE = 1000, SPLITS=5, FRAMESIZE=SIZE/(SPLITS);
    int populatedArr[SIZE];
    thread threads[SPLITS];

    populateNumbers(SIZE, populatedArr);


    //  = sumAll(SIZE, SIZE-FRAMESIZE-1 ,populatedArr); //This works
    for (int i = 0; i<SPLITS; i++){
        int rangeMax = FRAMESIZE*(i+1), rangeMin = rangeMax-FRAMESIZE+1;
        sumAll(rangeMax, rangeMin, populatedArr);
        printf("\n%d %d\n", rangeMax, rangeMin);
        // threads[i] = thread(sumAll, rangeMax, rangeMin, populatedArr);
    }

    // for (int i = 0; i<SPLITS; i++){
    //     threads[i].join(); 
    // }
    // double sum = sumAll(SIZE, populatedArr);
    
    cout << populatedArr[4] <<  " " << sum << endl;
}




