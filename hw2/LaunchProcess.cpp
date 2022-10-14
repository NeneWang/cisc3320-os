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
    char *inputfilename;
    cout<<"Please enter an input filename"<<endl;
    cin>>inputfilename;
    pid_t pid = fork();

    

    if(pid==0){
        
        char* argument_list[] = {inputfilename, NULL}; 

        execvp("./analyze.out", argument_list);
        exit(0);

    }if(pid > 0){
        wait(0);    
        int status;
        pid_t pid = 0;
        waitpid(pid, &status, 0);
        // pid_t wait(*status);    
        cout << "Exit value is: "<< status <<endl;

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        cout << "Time to finish all tasks: " << double(duration.count())/1000 << " ms" << endl;
    }
}




