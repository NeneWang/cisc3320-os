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

    int outer_page = 0;
    int inner_page = 0;

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
        printf("\nWith a 2-level page table, the outer page number (p1) is:: %d", this->outer_page);
        printf("\nWith a 2-level page table, the inner page number (p1) is:: %d", this->inner_page);
    }
};

class TranslateAddr
{

public:
    int address;
    TranslateAddr(const char *address)
    {
        long long int addr = atoll(address);
        if (addr > 4294967296)
        {
            throw invalid_argument("Value is not within the 32 bit range");
        }

        this->address = atoi(address);
    }

    void computeAddressInformation()
    {

        AddressInformation adrInfo(this->address);
        populateTablePositions(adrInfo);
        adrInfo.print_information();
    }

    void populateTablePositions(AddressInformation &addrInfo, int outerLevel= 10, int innerLevel=10){
        int inner_pages = pow(2, innerLevel);
        int outer = addrInfo.page_number/inner_pages;
        int inner = addrInfo.page_number%inner_pages;
        addrInfo.inner_page = inner;
        addrInfo.outer_page = outer;
    }


};
