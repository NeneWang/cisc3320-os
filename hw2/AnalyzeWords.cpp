#include <cstdlib>
#include <iostream>
#include <fstream>
#include <unordered_map>



#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <cmath>
#include <sstream>
#include <thread>
#include <chrono>
#include <ctime>
#include <mutex>

using namespace std;


#define ALPHACOUNT 26
#define ASCIIA 97
#define INPUTFILENAME "english_words.txt"


std::mutex acctLock;

// std::mutex acctLock;

void averageLength(ifstream inputFile, double &averageLetterCount){
    int countLines = 0;
    int countCharacters=0;
    string singleLine;

    // // Calculates the average length of all words
    // // Loop words and figures out the lenght, then add to counter and so.
    // while(inputFile){
    //     getline(inputFile, singleLine);
        
    //     int wordLen = singleLine.length();
    //     countLines++;
    //     countCharacters+=wordLen;


    // }

    // averageLetterCount = double(countCharacters)/countLines;

    // return double(countCharacters)/countLines;

}

void hello(){
    lock_guard<std::mutex> lock(acctLock);
    cout << "Hello world";
}



int GetRandom(int max){
    srand(time(NULL));
    return rand() % max;
}

std::string GetTime(){
    auto nowTime = std::chrono::system_clock::now();
    std::time_t sleepTime = 
            std::chrono::system_clock::to_time_t(nowTime);
    return std::ctime(&sleepTime);
}


double acctBalance = 100;

 
void GetMoney(int id,
        double withdrawal){
    
    // The exception safe way to protect access
    // to code within its scope. The lock is released 
    // after execution leaves this scope
    std::lock_guard<std::mutex> lock(acctLock);
    
    // Blocks access between lock and unlock
    // until execution completes
    // This isn't good to use however if an error 
    // occurs between lock and unlock
    // acctLock.lock();
    
    std::this_thread::sleep_for(std::chrono::seconds(3));
    
    std::cout << id << 
            " tries to withdrawal $" <<
            withdrawal << " on " <<
            GetTime() << "\n";
            
    if((acctBalance - withdrawal) >= 0){
        acctBalance -= withdrawal;
        std::cout << "New Account Balance is $" <<
                acctBalance << "\n";
    } else {
        std::cout << "Not Enough Money in Account\n";
        std::cout << "Current Balance is $" <<
                acctBalance << "\n";
    }
    // acctLock.unlock();
}

// int main(){
//     std::thread threads[10];
    
//     for(int i = 0; i < 10; ++i){
//         threads[i] = std::thread(GetMoney, i, 15);
//     }


//     for(int i = 0; i < 10; ++i){
//         threads[i].join();
//     }
    
//     return 0;
// }








int main(){
    int maxLen = 0;
    
    int characterCountArr[ALPHACOUNT] = {0};
    pthread_t t1, t2;

    int maxLetterCount = 0;
    char maxLetterChar;
    double averageLetterCount;

    ifstream inputFile; 

    inputFile.open(INPUTFILENAME);
    thread threads[3];
    // double averagelen = pthread_create(&t1, NULL, &averageLength,(double) inputFile);
    // pthread_join(t1, NULL)

    // threads[0] = thread(averageLength, inputFile, averageLetterCount);
    // threads[0] = thread(hello);
    threads[0] = std::thread(GetMoney, 1, 15);
    threads[1] = std::thread(hello);
    // threads[2] = std::thread(hello);
    threads[2] = std::thread(averageLength, inputFile, averageLetterCount);


    threads[0].join(); 
    threads[1].join(); 
    threads[2].join(); 

    cout<<"Average length " << averageLetterCount << endl;

}













