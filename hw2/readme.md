# Readme



**Attempt**
```cpp
#include <stdio.h>
#include <iostream>
#include <sys/wait.h>

#include <unistd.h>
#include <stdlib.h>
// #include <stdc++.h>
#include <iomanip> 

using namespace std;

int main(){
    clock_t start, end;
    pid_t pid = fork();

    if(pid==0){
        start = clock();
        ios_base::sync_with_stdio(false);
        cout << "child "  << pid << endl;
        char* argument_list[] = {"ls", "-l", NULL}; 
        execvp("ls", argument_list);
    
    }if(pid > 0){
        wait(0);
        cout << "Parent " << pid << endl;
        // time(&end);
        end = clock();
        double time_taken = double(end - start);
        cout << "Time taken by program is : " << fixed << time_taken << setprecision(5); 
        
    }
    
    // std::cout << "testing gnu" << endl;

}





```


Solution 2

```cpp
#include <stdio.h>
#include <iostream>
#include <sys/wait.h>

#include <unistd.h>
#include <stdlib.h>
#include <iomanip> 

using namespace std;

int main(){
    // time_t start, end;
    clock_t start, end;
    pid_t pid = fork();

    if(pid==0){
        start = clock();
        end = clock();
        // time(&start);
        ios_base::sync_with_stdio(false);
        // cout << "child "  << pid << endl;
        // char* argument_list[] = {"ls", "-l", NULL}; 
        char* argument_list2[] = { NULL}; 
        // char* argument_list[] = {"analyze.out", NULL}; 
        // execvp("ls", argument_list);
        execvp("./analyze.out", argument_list2);
        
        
    }if(pid > 0){
        wait(0);
        // cout << "Parent " << pid << endl;
        // time(&end);
        
        // double time_taken = double(end - start);
        double time_taken = (double(end - start/CLOCKS_PER_SEC) / double(CLOCKS_PER_SEC));

        cout <<  CLOCKS_PER_SEC << " " << start << " " << end << "Time taken by program is : " <<fixed << time_taken << setprecision(5); 
    
        
    }
    // std::cout << "testing gnu" << endl
}

```