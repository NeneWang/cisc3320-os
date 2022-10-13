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
#include <future>

using namespace std;


#define ALPHACOUNT 26
#define ASCIIA 97
#define INPUTFILENAME "english_words.txt"


std::mutex acctLock;

// std::mutex acctLock;



void hello(){
    lock_guard<std::mutex> lock(acctLock);
    cout << "Hello world";
}



void GetRandom(int max, int &random){
    srand(time(NULL));
    
    random = rand() % max;
    random = 15;
    // return rand() % max;
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



void func(std::promise<int> && p) {
    p.set_value(1);
}




int func2() { return 1; }

void averageLength(string inputFileName){
    
    ifstream inputFile;
    inputFile.open(inputFileName);
    int countLines = 0;
    int countCharacters=0;
    string singleLine;
    

    // // Calculates the average length of all words
    // // Loop words and figures out the lenght, then add to counter and so.
    while(inputFile){
        getline(inputFile, singleLine);
        
        int wordLen = singleLine.length();
        countLines++;
        countCharacters+=wordLen;


    }

    double averageLetterCount = double(countCharacters)/countLines;
    cout << "Average Lenth = " <<averageLetterCount << endl;
    // return double(countCharacters)/countLines;
}

void longestWord(string inputFileName){
    
    ifstream inputFile;
    inputFile.open(inputFileName);
    int maxLen = 0;
    string singleLine;
    // // Calculates the average length of all words
    // // Loop words and figures out the lenght, then add to counter and so.
    while(inputFile){
        getline(inputFile, singleLine);
        
        int wordLen = singleLine.length();
    
        maxLen = max(wordLen, wordLen);
    }
    
    cout << "Longest word length: "<< maxLen <<endl;
}


void mostFrequentLetter(string inputFileName){
    
    ifstream inputFile;
    inputFile.open(inputFileName);
    int maxLetterCount = 0;
    char maxLetterChar;
    int characterCountArr[ALPHACOUNT] = {0};
    string singleLine;
    // // Calculates the average length of all words
    // // Loop words and figures out the lenght, then add to counter and so.
    while(inputFile){
        getline(inputFile, singleLine);
        
        int wordLen = singleLine.length();
    
         for(int i = 0; i< wordLen ; i++){
                
                int arrCode = tolower(singleLine[i] - ASCIIA);
                if(arrCode > 25  | arrCode < 0){
                    continue;
                }
                                
                characterCountArr[
                     tolower(singleLine[i] - ASCIIA)
                ]++;
            }
            for(int i = 0; i< 26; i++ ){
            // cout << i << endl;
            if(i > maxLetterCount){
                maxLetterCount=characterCountArr[i];
                maxLetterChar = char(ASCIIA+i);
            }
            
        }
    }
    
    cout << "Most Frequent Letter: "<< maxLetterChar <<endl;
}




int main(){
    int maxLen = 0;
    
    int characterCountArr[ALPHACOUNT] = {0};
    pthread_t t1, t2;

    int maxLetterCount = 0;
    char maxLetterChar;
    double averageLetterCount;

    ifstream inputFile; 

    thread threads[3];

    threads[0] = std::thread(averageLength, INPUTFILENAME);
    threads[1] = std::thread(longestWord, INPUTFILENAME);
    threads[2] = std::thread(mostFrequentLetter, INPUTFILENAME);

    threads[0].join(); 
    threads[1].join(); 
    threads[2].join(); 
}













