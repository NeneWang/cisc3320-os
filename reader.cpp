#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

using namespace std;

void TraverseString(string &str, int N)
{ 
    // Traverse the string
    for (int i = 0; i < N; i++) {
  
        // Print current character
        if(isascii(str[i])){
            cout<< str[i]<< " ";
        }
        
    }
      
}

int main () {
    ifstream myfile; 
    std::string myline;
    myfile.open("shopping_list.txt");
    
    ofstream writeFile;
    writeFile.open("example.txt");
    writeFile << "Writing this to a file.\n";
    writeFile.close()

    
    if ( myfile.is_open() ) {
        while ( myfile ) { // equivalent to myfile.good()
            getline (myfile, myline);
            cout << endl;
            TraverseString(myline, myline.length());
        }
    }
    else {
        cout << "Couldn't open file\n";
    }
    return 0;  
}



