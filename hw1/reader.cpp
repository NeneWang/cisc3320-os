#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

void ProrcessLine(string &str, int lineLen, ofstream &writeFile)
{ 
    for (int i = 0; i < lineLen; i++) {
        if(isascii(str[i])){
            // cout<< str[i]<< " ";
            writeFile<<str[i];
        }
    }
}

int main () {
    ifstream inputFile; 
    ofstream writeFile;
    
    string myline;
    int countLines = 0;
    string inputfilename = "enter.txt";
    string outputfilename = "out.txt";
    
    cout<<"Please enter an input filename"<<endl;
    cin>>inputfilename;

    cout<<"Please enter an output filename"<<endl;
    cin>>outputfilename;

    inputFile.open(inputfilename);    
    writeFile.open(outputfilename);
    

    if ( inputFile.is_open() ) {
        while ( inputFile ) { 
            getline (inputFile, myline);
            countLines++;
            ProrcessLine(myline, myline.length(), writeFile);
            writeFile << endl;
        }
    }
    else {
        cout << "Couldn't open file\n";
    }
    
    cout << "Lines processed: " << countLines << endl;
    writeFile.close();
    return 0;  
}



