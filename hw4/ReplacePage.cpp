#include <iostream>
#include <vector>
#include <iostream>
#include <cstdio>
#include <math.h>
#include <string>
using namespace std;

class PageReplaceAlgo
{
    string reference;
    int desired_frame = 3;
    int length;
    string frames = "   ";
    int faults = 0;

public:
    PageReplaceAlgo(string reference, int desired_frame = 3, int refLen = 0)
    {
        this->reference = reference;
        this->desired_frame = desired_frame;
        this->length = reference.size();
        string spaces(this->length, ' ');
        this->frames = spaces;
    }

    // Simulates iteration of the as if it were using FIFO
    void iterateAsFifo()
    {
        int lastReferencedInPage = 0;
        for (int i = 0; i < length; i++)
        {
            // Append but if over the desired frame then go back and edit the one on the pointer
            char page = reference[i];
            bool faultFound = false;

            // Check if in the frames
            if (!(frames.find(page) < frames.length()))
            {
                // cout << "Fault: " << page << endl;
                // If found but however is larger than index 3(2) then go reference to the first (0)
                if (lastReferencedInPage >= this->desired_frame)
                {
                    lastReferencedInPage = 0;
                }

                // // If not found then add
                this->faults++;
                frames[lastReferencedInPage] = page;
                lastReferencedInPage++;
                faultFound = true;
            }
            this->printFrames(page, faultFound);
        }
    }
    
    // Simulates iteration of the as using 
    void iterateAsFifo()
    {
        int lastReferencedInPage = 0;
        for (int i = 0; i < length; i++)
        {
            // Append but if over the desired frame then go back and edit the one on the pointer
            char page = reference[i];
            bool faultFound = false;

            // Check if in the frames
            if (!(frames.find(page) < frames.length()))
            {
                // cout << "Fault: " << page << endl;
                // If found but however is larger than index 3(2) then go reference to the first (0)
                if (lastReferencedInPage >= this->desired_frame)
                {
                    lastReferencedInPage = 0;
                }

                // // If not found then add
                this->faults++;
                frames[lastReferencedInPage] = page;
                lastReferencedInPage++;
                faultFound = true;
            }
            this->printFrames(page, faultFound);
        }
    }

    void printResults(const char *prepend = "")
    {
        printf("\n%s: total # of page fault is: %d ", prepend, this->faults);
    }

    void printFrames(char currentPage, bool faultFound)
    {
        string message = "";
        if (faultFound)
            message = this->frames;

        cout << endl
             << currentPage << ": " << message;
    }

    // The idea is to keep a pointer of the last on the array
};