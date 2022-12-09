#include "acutest.hpp"
#include "main.cpp"
#include "utils.cpp"

#include <iostream>
#include <vector>
#include "TranslateAddr.cpp"
#include "ReplacePage.cpp"

using namespace std;

void part_1(void)
{
    TranslateAddr ta("20221108");
    ta.computeAddressInformation();
}

void part_2(void)
{
    
    string reference = "70120304230321201701";
    FIFO fifo(reference, 3, reference.size());
    fifo.iterate();
    


}


TEST_LIST = {
    // {"test_p4", test_p4},
    // {"part_1", part_1},
    {"part_2", part_2},
    {0}};