#include <iostream>
#include <vector>
#include <iostream>
#include <cstdio>
#include <math.h>
#include <string>
#include <climits>
#include <random>
using namespace std;

string randomPageRef(int length = 10)
{
    string CHARACTER_POOL = "0123456789";
    int POOL_SIZE = CHARACTER_POOL.size();
    string result = "";
    // random_device rd;  // obtain a random number from hardware
    // mt19937 gen(rd()); // seed the generator
    // uniform_int_distribution<> distr(0, 10);

    for (int i = 0; i < length; i++)
    {
        // gen random num
        // int rndIndex =
        // result+=
        // cout << distr(gen);
        // cout << ;
        result += CHARACTER_POOL[rand() % POOL_SIZE];
    }
    return result;
}

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
        this->length = reference.length();
        string spaces(desired_frame, ' ');
        this->frames = spaces;
    }

    // Simulates iteration of the as if it were using FIFO
    void iterateAsFifo(bool debug=true)
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

            if(debug) this->printFrames(page, faultFound);
        }
    }

    // Simulates iteration of the as using LURI
    void iterateAsLRU(bool debug=true)
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
                    this->replaceLargest(page, ageVect);
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
            if(debug) this->printFrames(page, faultFound);
        }
    }

    // Optimal Iteration
    void iterateAsOptimal(bool debug=true)
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
                if (lastReferencedInPage >= this->desired_frame)
                {
                    // Run replacement by age.
                    this->optimalChange(page, i);
                    // cout << "\n\nRunning optimal";
                }
                else
                {
                    frames[lastReferencedInPage] = page;
                    lastReferencedInPage++;
                }

                this->faults++;

                faultFound = true;
            }

            if(debug) this->printFrames(page, faultFound);
        }
    }

    void replaceLargest(char newPage, vector<int> &ageVector)
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
        // cout << "\nOldest age at " << oldestAge << " index " << oldestIndex << endl;
        resetAge(ageVector, oldestIndex);

        // Replace
        this->frames[oldestIndex] = newPage;
    }

    void printAges(vector<int> &ageVetor)
    {
        cout << endl;
        for (int age : ageVetor)
        {
            cout << age << '-';
        }
        cout << endl;
    }

    void optimalChange(char newPage, int turn)
    {
        // For each item in the frame check create vector with largest and index.
        // Then grab smaller and use that index to replace
        vector<int> willBeReplacedInXTurns;

        for (char page : this->frames)
        {

            int turnToBeSeen = this->willBeSeenAtTurn(turn, page);
            // cout << "\n appending " << page << " from pages " << turnToBeSeen << endl;
            willBeReplacedInXTurns.push_back(turnToBeSeen);
        }
        // cout << "\nsize " << willBeReplacedInXTurns.size();
        this->replaceLargest(newPage, willBeReplacedInXTurns);
    }

    int willBeSeenAtTurn(int currentTurn, char targetCharacter)
    {
        for (int idx = currentTurn; idx < this->length; idx++)
        {
            if (targetCharacter == this->reference[idx])
            {
                // The further in the turns
                return idx;
            }
        }
        return INT_MAX; // means to be replaced cause ti will never be seen
    }

    void ageOlder(vector<int> &ageVector)
    {
        for (auto it = ageVector.begin(); it != ageVector.end(); ++it)
        {
            // cout << "Agging older?" << endl;
            *it = *it + 1;
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