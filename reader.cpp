#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

void TraverseString(string &str, int N, ofstream &writeFile)
{ 
    // Traverse the string
    for (int i = 0; i < N; i++) {
  
        // Print current character
        if(isascii(str[i])){
            cout<< str[i]<< " ";
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
    string outputfilename = "out.txt"
    
    cout<<"Please enter an input filename"<<endl;
    cin>>inputfile;

    cout<<"Please enter an output filename"<<endl;
    cin>>outputfilename;

    inputFile.open(inputfile);    
    writeFile.open(writeFile);
    

    if ( inputFile.is_open() ) {
        while ( inputFile ) { 
            getline (inputFile, myline);
            countLines++;
            TraverseString(myline, myline.length(), writeFile);

            cout << endl;
            writeFile << endl;
        }
    }
    else {
        cout << "Couldn't open file\n";
    }
    
    cout << "Lines processed:" << countLines << endl;
    writeFile.close();
    return 0;  
}



