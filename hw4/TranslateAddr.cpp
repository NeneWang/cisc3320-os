#include <iostream>
#include <vector>

#include <iostream>

#include <cstring>

#include <cstdlib>

#include <cstdio>

using namespace std;

#define Pg_no_mask 0xFFFFF000

#define offset_mask 0x00000FFF

using namespace std;

struct AddressInformation
{

    int largest_page_number;
    int page_table;
    int page_number;
    int offset;
};

class TranslateAddr
{

public:
    const char *address;
    TranslateAddr(const char *address)
    {

        this->address = address;
    }

    bool verifyAddress()
    {
    }
    void computeAddressInformation()
    {

        int Pg_no, offset;
        unsigned int reference;

        reference = (unsigned int)atoi(this->address);

        cout << "the address contains " << reference << endl;

        Pg_no = (reference & Pg_no_mask) >> 12;

        offset = reference & offset_mask;

        cout << "page number = " << Pg_no << endl;

        cout << "offset = " << offset;
    }
};
