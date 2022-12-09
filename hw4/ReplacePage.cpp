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

    // Simulates iteration of the as using LURI
    void iterateAsLRU()
    {
        int lastReferencedInPage = 0;
        vector<int> ageVect; // The idea is to have an age vect for the elements.
        for (int i = 0; i < length; i++)
        {
            // Append but if over the desired frame then go back and edit the one on the pointer
            char page = reference[i];
            bool faultFound = false;
            // Check if in the frames
            if (!(frames.find(page) < frames.length()))
            {
                // cout << "Fault: " << page << endl;
                // Update age for all
                // If found but however is larger than index 3(2) then go reference to the first (0)
                if (lastReferencedInPage >= this->desired_frame)
                {
                    // Run replacement by age.
                    this->replaceOldest(page, ageVect);
                }
                else
                {
                    frames[lastReferencedInPage] = page;
                    ageVect.push_back(0);
                    lastReferencedInPage++;
                }

                this->faults++;

                // // If not found then add
                faultFound = true;
            }
            else
            {

                int foundAt = frames.find(page);

                // cout << endl
                //      << page << " Found at: "
                //      << foundAt<< " reseting age: " << ageVect.at(1)<< endl;
                
                resetAge(ageVect, foundAt);
            }

            this->ageOlder(ageVect);
            // cout<<"\naged: "<<endl;
            this->printFrames(page, faultFound);
        }
        
    }

    void replaceOldest(char newPage, vector<int> &ageVector)
    {
        // Find the largest one, replace it, and also reset it's age vector (in its index)
        int oldestAge = 0;
        int oldestIndex = 0;
        

        for (int i = 0; i < ageVector.size(); i++)
        {
            
        
            int currentAge = ageVector[i];
            if (currentAge > oldestAge)
            {
                oldestAge = currentAge;
                oldestIndex = i;
            }
        }
        // cout << "\nOldest age at " << oldestAge << " index "<< oldestIndex << endl;
        resetAge(ageVector, oldestIndex);
        
        // Replace
        this->frames[oldestIndex] = newPage;
    }

    void printAges(vector<int> &ageVetor){
        cout << endl;
        for (int age:ageVetor){
            cout << age<<'-';
        }
        cout << endl;
    }

    void ageOlder(vector<int> &ageVector)
    {
        for (auto it = ageVector.begin(); it != ageVector.end(); ++it)
        {
        // cout << "Agging older?" << endl;
            *it = *it+1;
        }
    }

    void resetAge(vector<int> &ageVector, int index)
    {
        // Resets the age in specified index
        
        ageVector[index] = 0;
    }

    void printResults(const char *prepend = "")
    {
        printf("\n%s: total # of page fault is: %d ", prepend, this->faults);
    }

    void printFrames(char currentPage, bool faultFound)
    {
        string message = "";
        // faultFound = true;
        if (faultFound)
            message = this->frames;

        cout << endl
             << currentPage << ": " << message;
    }

    // The idea is to keep a pointer of the last on the array
};