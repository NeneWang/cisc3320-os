#include "acutest.hpp"
#include "main.cpp"
#include "utils.cpp"

#include <iostream>
#include <vector>
#include "TranslateAddr.cpp"

using namespace std;


void part1_test_problem_1_address(void){
    TranslateAddr ta("20221108");
    ta.computeAddressInformation();
}

void test_p4(void){
    vector<int> res = p4(2); //Should return 2
    TEST_ASSERT_(res.at(0) == 4, "Checking valueasd");
    loop_vect(res);   
}


TEST_LIST = {
    {"test_p4", test_p4},
    {"part1_test_problem_1_address", part1_test_problem_1_address},
    {0}};