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
    ifstream myfile; 
    string myline;
    string inputfile = "shopping_list.txt";
    
    cout<<"Please enter an input file"<<endl;
    cin>>inputfile;



    myfile.open(inputfile);
    
    ofstream writeFile;
    writeFile.open("example.txt");
    // writeFile << "Writing this to a file.\n";
    


    if ( myfile.is_open() ) {
        while ( myfile ) { 
            getline (myfile, myline);
            

            TraverseString(myline, myline.length(), writeFile);

            cout << endl;
            writeFile << endl;
        }
    }
    else {
        cout << "Couldn't open file\n";
    }
    writeFile.close();
    return 0;  
}



