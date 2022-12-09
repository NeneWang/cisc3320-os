#include <iostream>
#include <vector>
#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

#define page_number_mask 0xFFFFF000
#define offset_mask 0x00000FFF

using namespace std;

struct AddressInformation
{
    int address = 0;
    int largest_page_number = 0;
    long long table_size = 0;
    int page_number = 0;
    int offset = 0;
    const int LOGICAL_BITS = 32;
    const int PAGE_SIZE = pow(2, 12);
    const int ENTRY_SIZE = 4; // In bytes
    const int BYTE_IN_MEGABYTE = 1000000;

    AddressInformation(int address)
    {
        this->largest_page_number = pow(2, this->LOGICAL_BITS) / PAGE_SIZE;
        // Assuming each entry is 4 bytes
        // this->table_size = pow(2, largest_page_number * ENTRY_SIZE);
        this->address = address;
        this->page_number = (address & page_number_mask) >> 12;
        this->offset = (address & offset_mask);
    }

    void print_information()
    {
        // Prints in the format requested
        printf("\nThe largest possible page number is: %d", largest_page_number);
        printf("\nThe page table size is:2 ^ *%d * %d) bytes. ", largest_page_number, ENTRY_SIZE);
        printf("\nGiven the address of  %d", address);
        printf("\nThe page number is: %d", page_number);
        printf("\nThe page offset is: %d", offset);
    }
};

class TranslateAddr
{

public:
    int address;
    TranslateAddr(const char *address)
    {

        this->address = atoi(address);
    }

    bool verifyAddress()
    {
    }

    void computeAddressInformation()
    {

        AddressInformation adrInfo(this->address);
        adrInfo.print_information();
    }
};
