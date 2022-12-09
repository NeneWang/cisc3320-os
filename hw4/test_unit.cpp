#include "acutest.hpp"
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

void part_2_fifo(void)
{

    string reference = "70120304230321201701";
    PageReplaceAlgo fifo(reference, 3);
    fifo.iterateAsFifo();
    fifo.printResults("FIFO");
}

void part_2_LRU(void)
{

    string reference = "70120304230321201701";
    PageReplaceAlgo lru(reference, 3);
    lru.iterateAsLRU();
    lru.printResults("LRU using 70120304230321201701 ");
}

void part_2_LRU_2(void)
{

    string reference = "701203042303212";
    PageReplaceAlgo lru(reference, 3);
    lru.iterateAsLRU();
    lru.printResults("LRU using 701203042303212");
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

void part_3_opt(void)
{

    string reference = "70120304230321201701";
    PageReplaceAlgo opt(reference, 3);
    opt.iterateAsOptimal();
    opt.printResults("Optimal using 70120304230321201701 ");
}

void part_3_opt_2(void)
{
    // https://www.youtube.com/watch?v=XmdgDHhx0fg&ab_channel=TechXArena

    string reference = "2342137543";
    PageReplaceAlgo opt(reference, 3);
    opt.iterateAsOptimal();
    opt.printResults("Optimal using 2142137543 ");
}

void test_random(void){
    cout << randomPageRef(10) << endl;
    cout << randomPageRef(100) << endl;
    cout << randomPageRef(12) << endl;
}

TEST_LIST = {
    // {"test_random", test_random},
    // {"part_1", part_1},
    // {"part_2", part_2_fifo},
    // {"part_2_LRU", part_2_LRU},
    // {"part_2_LRU_2", part_2_LRU_2},
    // {"part_2_belady", part_2_belady},
    {"part_3_opt", part_3_opt},
    // {"part_3_opt_2", part_3_opt_2},
    {0}};