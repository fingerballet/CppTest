/* *******************************************************
 *
 * This file is just for running all the test cases of gtest;
 * The end-to-end test is in SimulationTest.cpp
 *
 * *******************************************************/

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
