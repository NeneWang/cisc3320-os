#include <stdio.h>
#include <iostream>
#include <sys/wait.h>

#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main(){

    pid_t pid = fork();
    if(pid==0){
        cout << "child "  << pid << endl;
        char* argument_list[] = {"ls", "-l", NULL}; 
        execvp("ls", argument_list);
    
    }if(pid > 0){
        wait(0);
        cout << "Parent " << pid << endl;
    }
    
    // std::cout << "testing gnu" << endl;

}




