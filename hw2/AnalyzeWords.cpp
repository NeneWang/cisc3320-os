#include <cstdlib>
#include <iostream>
#include <fstream>


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


std::string GetTime(){
    auto nowTime = std::chrono::system_clock::now();
    std::time_t sleepTime = 
            std::chrono::system_clock::to_time_t(nowTime);
    return std::ctime(&sleepTime);
}

void averageLength(){
    // Calculates the average length of all words
    // Loop words and figures out the lenght, then add to counter and so.
}


int main(){
    string inputfilename = "english_words.txt";
    // string outputfilename = "out.txt";
    string myline;
    int countLines = 0;

    ifstream inputFile; 

    cout<<"Please enter an input filename"<<endl;
    cin>>inputfilename;

    inputFile.open(inputfilename);  
    
    if ( inputFile.is_open() ) {
        while ( inputFile ) { 
            getline (inputFile, myline);
            // ProrcessLine(myline, myline.length(), writeFile, countCharactersStripped);
            
            countLines++;
        }
    }

    





}




