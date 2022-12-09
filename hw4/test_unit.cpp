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

void part_1_b_error(void)
{
    TranslateAddr ta("4294967299");
    

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

void part_3_opt_random(void)
{
    string reference = randomPageRef(1000);
    for (int framePages = 1; framePages <= 7; framePages++)
    {
        string type, message;

        PageReplaceAlgo fifo(reference, framePages);
        fifo.iterateAsFifo(false);
        type = "FIFO";
        message = type +", with " + to_string(framePages) + " pages ";
        fifo.printResults(message.c_str());

        PageReplaceAlgo lru(reference, framePages);
        lru.iterateAsLRU(false);
        type = "LRU";
        message = type +", with " + to_string(framePages) + " pages ";
        lru.printResults(message.c_str());


        PageReplaceAlgo opt(reference, framePages);
        opt.iterateAsOptimal(false);
        type = "Optimal";
        message = type +", with " + to_string(framePages) + " pages ";
        opt.printResults(message.c_str());
        cout << "\n" << endl;
    }
}

void part_3_opt_partial(void)
{
    string reference = randomPageRef(1000);
    for (int framePages = 1; framePages <= 7; framePages++)
    {
        string type, message;


        PageReplaceAlgo opt(reference, framePages);
        opt.iterateAsOptimal(false);
        int opt_faults = opt.faults;
        
        PageReplaceAlgo fifo(reference, framePages);
        fifo.iterateAsFifo(false);
        int fifo_faults = fifo.faults;

        PageReplaceAlgo lru(reference, framePages);
        lru.iterateAsLRU(false);
        int lru_faults = lru.faults;

        printf("\n%d: %d, %d(%d%%), %d(%d%%)", 
        framePages, opt_faults, fifo_faults, getPercentage(fifo_faults, opt_faults), lru_faults, getPercentage(lru_faults, opt_faults));
    }
}

void test_random(void)
{
    cout << randomPageRef(10) << endl;
    cout << randomPageRef(100) << endl;
    cout << randomPageRef(12) << endl;
}

TEST_LIST = {
    // {"test_random", test_random},
    {"part_1_b_error", part_1_b_error},
    // {"part_1", part_1},
    // {"part_2", part_2_fifo},
    // {"part_2_LRU", part_2_LRU},
    // // {"part_2_LRU_2", part_2_LRU_2},
    // {"part_2_belady", part_2_belady},
    // {"part_3_opt", part_3_opt},
    // // {"part_3_opt_2", part_3_opt_2},
    // // {"part_3_opt_random", part_3_opt_random},
    // {"part_3_opt_partial", part_3_opt_partial},
    {0}};