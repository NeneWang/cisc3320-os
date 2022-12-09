#include <iostream>
#include <vector>
#include <iostream>
#include <cstdio>
#include <math.h>
#include <stdexcept>

using namespace std;

#define page_number_mask 0xFFFFF000
#define offset_mask 0x00000FFF
#define mask_32_bit 0xffffffff

using namespace std;

struct AddressInformation
{
    int address = 0;
    int largest_page_number = 0;
    long table_size = 0;
    int page_number = 0;
    int offset = 0;
    const int LOGICAL_BITS = 32;
    const int PAGE_SIZE = pow(2, 12); // 4kb ; 12 bits
    const int ENTRY_SIZE = 4;         // In bytes
    const int BYTE_IN_MEGABYTE = 1000000;
    const int OUTERPAGEENTRY = 10; // 1024 entrie -> 10 buts ;
    // 32 = OUTERPAGEENTRY + 12 + x => x = 10

    AddressInformation(unsigned long long address)
    {
        this->largest_page_number = pow(2, this->LOGICAL_BITS) / PAGE_SIZE;
        // Assuming each entry is 4 bytes
        this->table_size = largest_page_number * ENTRY_SIZE;
        this->address = address;
        this->page_number = (address & page_number_mask) >> 12;
        this->offset = (address & offset_mask);
    }

    void print_information()
    {
        // Prints in the format requested
        printf("\nThe largest possible page number is: %d", largest_page_number);
        printf("\nThe page table size is: %d bytes. ", table_size);
        printf("\nGiven the address of  %d", address);
        printf("\nThe page number is: %d", page_number);
        printf("\nThe page offset is: %d", offset);
        printf("\nWith a 2-level page table, the outer page number (p1) is:: %d", OUTERPAGEENTRY);
        printf("\nWith a 2-level page table, the inner page number (p1) is:: %d", OUTERPAGEENTRY);
    }
};

class TranslateAddr
{

public:
    int address;
    TranslateAddr(const char *address)
    {
        long int addr = stol(address);
        if (addr > 4294967296)
        {
            throw invalid_argument("Value is not within the 32 bit range");
        }

        this->address = atoi(address);
    }

    bool verifyAddress()
    {
        return false;
    }

    void computeAddressInformation()
    {

        AddressInformation adrInfo(this->address);
        adrInfo.print_information();
    }
};
