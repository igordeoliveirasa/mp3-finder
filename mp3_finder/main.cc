/* 
 * File:   main.cc
 * Author: igor
 *
 * Created on September 17, 2014, 6:23 AM
 */

#include <cstdlib>
#include <gtest/gtest.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    return 0;
}


int TwoTimes(int n) {
    return n * 2;
}


TEST(TwoTimesTest, FourReturn) {
  EXPECT_EQ(4, TwoTimes(2));
}
