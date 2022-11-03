#include <iostream>

using namespace std;

void populateNumbers(int range, int *array){
    for(int i = 1; i<=range; i++){
        array[i-1] = i;
    }
}

int main(){
    const int SIZE = 1000, SPLITS=5, QUARTER=SIZE/(SPLITS-1);
    int populatedArr[SIZE];
    populateNumbers(SIZE, populatedArr);
    
    cout << populatedArr[4] << endl;
}




