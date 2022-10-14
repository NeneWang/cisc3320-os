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
    
        maxLen = max(maxLen, wordLen);
    }
    
    cout << "Longest word length: "<< maxLen <<endl;
}


void mostFrequentLetter(string inputFileName){
    
    ifstream inputFile;
    inputFile.open(inputFileName);
    long maxLetterCount = 0;
    char maxLetterChar;
    int characterCountArr[ALPHACOUNT] = {0};
    string singleLine;
    // // Calculates the average length of all words
    // // Loop words and figures out the lenght, then add to counter and so.
    while(inputFile){
        getline(inputFile, singleLine);
        
        int wordLen = singleLine.length();
    
         for(int i = 0; i< wordLen ; i++){
                
                int arrCode = tolower(singleLine[i] ) - ASCIIA;
                if(arrCode >= 26  | arrCode < 0){
                    continue;
                }
                                
                characterCountArr[
                     arrCode
                ]++;
                // cout << "arrcode got "<< singleLine[i] <<" " <<arrCode <<endl;
            }
            for(int i = 0; i < 26; i++ ){
            // cout << i << endl;
            char let = char(i + ASCIIA );
            // cout<<"\nchar alpha "<< let << " "<< i << " "<< tolower(let)- ASCIIA  << " "<<characterCountArr[i];
            
            if(characterCountArr[i] > maxLetterCount){
                maxLetterCount=characterCountArr[i];
                maxLetterChar = char(ASCIIA+ i );
                // cout<<characterCountArr[i]<<endl;
                
            }
            
        }
    }
    
    // cout << char(ASCIIA)<<"Most Frequent Letter: "<< maxLetterChar <<maxLetterCount<<endl;
    cout <<"Most Frequent Letter: "<< maxLetterChar <<endl;
}




int main(int argc, char* argv[]){
    int maxLen = 0;
    
    int characterCountArr[ALPHACOUNT] = {0};
    pthread_t t1, t2;

    int maxLetterCount = 0;
    char maxLetterChar;
    double averageLetterCount;

    ifstream inputFile; 

    thread threads[3];

    string inputfilename;
    if(argc > 0){
        inputfilename = argv[1];
    }else{
        inputfilename = INPUTFILENAME;
    }

    threads[0] = std::thread(averageLength, inputfilename);
    threads[1] = std::thread(longestWord, inputfilename);
    threads[2] = std::thread(mostFrequentLetter, inputfilename);

    threads[0].join(); 
    threads[1].join(); 
    threads[2].join(); 
}













