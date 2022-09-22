#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

// Process Line by going character by character and writes in the target writefile if is the character is ascii
void ProrcessLine(string &str, int lineLen, ofstream &writeFile, int &countCharactersStripped)
{ 
    for (int i = 0; i < lineLen; i++) {
        if(isascii(str[i])){
            // cout<< str[i]<< " ";
            writeFile<<str[i];
        }else{
            countCharactersStripped++;
        }
    }
    writeFile << endl;
}

int main () {
    ifstream inputFile; 
    ofstream writeFile;
    
    string myline;
    int countLines = 0, countCharactersStripped = 0;
    //Default namefiles, in case you want to comment out the cin statements below.
    string inputfilename = "enter.txt";
    string outputfilename = "out.txt";
    
    cout<<"Please enter an input filename"<<endl;
    cin>>inputfilename;

    cout<<"Please enter an output filename"<<endl;
    cin>>outputfilename;

    inputFile.open(inputfilename);    
    writeFile.open(outputfilename);
    
    // If inputfilename found, and able to open it, process each line, add to the counter
    if ( inputFile.is_open() ) {
        while ( inputFile ) { 
            getline (inputFile, myline);
            ProrcessLine(myline, myline.length(), writeFile, countCharactersStripped);
            
            countLines++;
        }
    }
    else {
        cout << "File not found"<<endl;
    }
    
    cout << "Lines processed: " << countLines << ", Characters Stripped " << countCharactersStripped << endl;
    writeFile.close();
    return 0;  
}



