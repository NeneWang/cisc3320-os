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
    int maxLen = 0;
    int countCharacters;
    int characterCountArr[26] = {0};
    int maxLetterCount = 0;
    char maxLetterChar;

    ifstream inputFile; 
    // unordered_map word_map;

    // cout<<"Please enter an input filename"<<endl;
    // cin>>inputfilename;

    inputFile.open(inputfilename);  
    
    if ( inputFile.is_open() ) {
        while ( inputFile ) {
            getline (inputFile, myline);
            int wordLen = myline.length();
            // ProrcessLine(myline, myline.length(), writeFile, countCharactersStripped);
            // cout << "Line n: "<< countLines  << " "  << myline<< " "<< myline.length() <<endl;
            countLines++;
            countCharacters+=wordLen;
            maxLen = max(wordLen, maxLen);
            
            for(int i = 0; i< wordLen ; i++){
                // cout << myline << " : ";
                int arrCode = tolower(myline[i] - 97);
                if(arrCode > 25  | arrCode < 0){
                    continue;
                }
                // cout << << endl;
                
                characterCountArr[
                     tolower(myline[i] - 97)
                ]++;
            }

        }
        for(int i = 0; i< 26; i++ ){
            // cout << i << endl;
            if(i > maxLetterCount){
                maxLetterCount=characterCountArr[i];
                maxLetterChar = char(96+i);
            }
            
        }
    }


    int meanWordLen = countCharacters / countLines;

    cout << countLines << "max len word" << maxLen << " Mean word len" << meanWordLen <<endl;
    cout << maxLetterChar << " : " << maxLetterCount << endl;    


}




