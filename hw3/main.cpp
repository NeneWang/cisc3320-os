#include <iostream>

using namespace std;

void populateNumbers(int range, int *array){
    for(int i = 1; i<=range; i++){
        array[i-1] = i;
    }
}

int main(){

    int populatedArr[10];
    populateNumbers(10, populatedArr);
    cout << populatedArr[4] << endl;
}




