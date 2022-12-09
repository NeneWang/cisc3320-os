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
    PageReplaceAlgo fifo(reference, 3);
    fifo.iterateAsFifo();
    fifo.printResults("FIFO");
}

void part_2_belady(void)
{

    string reference = "123412512345";
    PageReplaceAlgo fifo_3(reference, 3);
    fifo_3.iterateAsFifo();
    fifo_3.printResults("3 Frames FIFO");

    
    PageReplaceAlgo fifo_4(reference, 4);
    fifo_4.iterateAsFifo();
    fifo_4.printResults("4 Frames FIFO");
}

TEST_LIST = {
    // {"test_p4", test_p4},
    // {"part_1", part_1},
    {"part_2", part_2},
    {"part_2_belady", part_2_belady},
    {0}};