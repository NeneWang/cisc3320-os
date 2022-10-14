#include <stdio.h>
#include <iostream>
#include <sys/wait.h>

#include <unistd.h>
#include <stdlib.h>
#include <iomanip> 
#include <chrono>
using namespace std::chrono;
 

using namespace std;

int main(){
    auto start = high_resolution_clock::now();
    pid_t pid = fork();

    if(pid==0){
        ios_base::sync_with_stdio(false);
        char* argument_list2[] = { NULL}; 
        execvp("./analyze.out", argument_list2);
    }if(pid > 0){
        wait(0);    
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    }
}




