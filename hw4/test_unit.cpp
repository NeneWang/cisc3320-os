#include "acutest.hpp"
#include "main.cpp"
#include "utils.cpp"

#include <iostream>
#include <vector>
#include "TranslateAddr.cpp"

using namespace std;


void part_1(void){
    TranslateAddr ta("20221108");
    ta.computeAddressInformation();
}

void part_2(void){
    
}

void test_p4(void){
    vector<int> res = p4(2); //Should return 2
    TEST_ASSERT_(res.at(0) == 4, "Checking valueasd");
    loop_vect(res);   
}


TEST_LIST = {
    // {"test_p4", test_p4},
    {"part_1", part_1},
    {0}};