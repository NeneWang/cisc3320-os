#include <stdio.h>
#include <iostream>
#include <sys/wait.h>

#include <unistd.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int main(){
    time_t start, end;
    pid_t pid = fork();

    if(pid==0){
        time(&start);
        ios_base::sync_with_stdio(false);
        cout << "child "  << pid << endl;
        char* argument_list[] = {"ls", "-l", NULL}; 
        execvp("ls", argument_list);
    
    }if(pid > 0){
        wait(0);
        cout << "Parent " << pid << endl;
        time(&end);
        double time_taken = double(end - start);
        cout << "Time taken by program is : " << fixed
            << time_taken << setprecision(5);
        cout << " sec " << endl;
    }
    
    // std::cout << "testing gnu" << endl;

}




