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
#define INPUTFILENAME english_words.txt

std::string GetTime(){
    auto nowTime = std::chrono::system_clock::now();
    std::time_t sleepTime = 
            std::chrono::system_clock::to_time_t(nowTime);
    return std::ctime(&sleepTime);
}



void averageLength(ifstream &inputFile){
    int countLines = 0;
    int countCharacters;


    // Calculates the average length of all words
    // Loop words and figures out the lenght, then add to counter and so.
}


int main(){
    string myline;
    
    int maxLen = 0;
    
    int characterCountArr[ALPHACOUNT] = {0};

    
    int maxLetterCount = 0;
    char maxLetterChar;


    ifstream inputFile; 

    inputFile.open(inputfilename);
    averageLength(inputFile)











}













