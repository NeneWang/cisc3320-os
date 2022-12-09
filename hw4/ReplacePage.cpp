#include <iostream>
#include <vector>
#include <iostream>
#include <cstdio>
#include <math.h>
#include <string>
using namespace std;

class FIFO
{
    string reference;
    int desired_frame = 3;
    int length;
    string frames="   ";
    int faults = 0;

public:
    FIFO(string reference, int desired_frame = 3, int refLen = 0)
    {
        this->reference = reference;
        this->desired_frame = desired_frame;
        this->length = reference.size();
        string spaces(this->length, ' ');
        this->frames = spaces;
        
    }

    // Simulates iteration of the frames
    void iterate()
    {
        int lastReferencedInPage = 0;
        for (int i = 0; i < length; i++)
        {
            // Append but if over the desired frame then go back and edit the one on the pointer
            char page = reference[i];

            // Check if in the frames
            if (frames.find(page) < frames.length())
            {
            }
            else
            {
                cout << "Fault: "<< page << endl;
                // If found but however is larger than index 3(2) then go reference to the first (0)
                if (lastReferencedInPage >= this->desired_frame)
                {
                    lastReferencedInPage = 0;
                }

                // // If not found then add
                // frames+=page;
                frames[lastReferencedInPage] = page;
                lastReferencedInPage++;
                cout<<frames<<endl;
                this->printFrames();
            }
            // this->printFrames();
        }
    }

    void printFrames()
    {
        // Iterate pages in frame and print them

        // for (char page : frames)
        // {
        //     cout << page << " ";
        // }

        cout << frames << endl;
    }

    // The idea is to keep a pointer of the last on the array
};