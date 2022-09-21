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
        cout<< str[i]<< " ";
    }
      
}

int main () {
    ifstream myfile; 
    std::string myline;
    myfile.open("shopping_list.txt");
    if ( myfile.is_open() ) {
        while ( myfile ) { // equivalent to myfile.good()
            getline (myfile, myline);
            cout << myline << '\n';
            TraverseString(myline, myline.length());
            // if (isascii(c)){

            // }
        }
    }
    else {
        cout << "Couldn't open file\n";
    }
    return 0;  
}



