#include <iostream>

using namespace std;

void populateNumbers(int range, int *array){
    for(int i = 1; i<=range; i++){
        array[i-1] = i;
    }
}

long sumAll(int range, int arrayNums[]){
    long sum = 0;
    for(int i = 0; i < range; i++){
        sum+=arrayNums[i];
    }

    return sum;
}

int main(){
    const int SIZE = 1000, SPLITS=5, FRAMESIZE=SIZE/(SPLITS-1);
    int populatedArr[SIZE];
    populateNumbers(SIZE, populatedArr);

    double sum = sumAll(FRAMESIZE, populatedArr); //This works
    // double sum = sumAll(SIZE, populatedArr);
    cout << populatedArr[4] <<  " " << sum << endl;
}




