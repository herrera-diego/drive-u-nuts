#include "gtest/gtest.h"
#include <string>

#include <stdio.h>
#include <unistd.h>

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include "gameSolver.h"

using namespace DriveYaNuts;
using namespace std;

class TestSolver : public testing::Test 
{
    public: 

    void SetUp() override {  }
    void TearDown() override {  }

    // Per-test-suite set-up.
    // Called before the first test in this test suite.
    // Can be omitted if not needed.
    static void SetUpTestSuite() 
    {

    }

    // Per-test-suite tear-down.
    // Called after the last test in this test suite.
    // Can be omitted if not needed.
    static void TearDownTestSuite() 
    {

    }
};

TEST_F(TestSolver, NutsPopulate) 
{
    GameSolver testSolver; 
    testing::internal::CaptureStdout();
    testSolver.printNuts();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expectedResult = 
        "Nuts: \n"
        "1 2 3 4 5 6 \n"
        "1 6 4 2 5 3 \n"
        "2 1 6 5 4 3 \n"
        "1 4 6 2 3 5 \n"
        "4 5 3 1 6 2 \n"
        "1 6 5 3 2 4 \n"
        "6 5 2 1 4 3 \n";

    ASSERT_EQ ( output , expectedResult );
}


TEST_F(TestSolver, NutsChange) 
{
    int values[NUMBER_OF_NUTS][NUT_SIZE] = {
        {1,2,3,4,5,6}, //South 
        {1,2,3,4,5,6}, //SW
        {1,2,3,4,5,6}, //NW
        {0,0,0,0,0,0}, //North
        {1,2,3,4,5,6}, //Center
        {1,2,3,4,5,6}, //NE
        {1,2,3,4,5,6} //SE
    };

    GameSolver testSolver; 
    testing::internal::CaptureStdout();
    testSolver.printNuts();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expectedResult = 
        "Nuts: \n"
        "1 2 3 4 5 6 \n"
        "1 6 4 2 5 3 \n"
        "2 1 6 5 4 3 \n"
        "1 4 6 2 3 5 \n"
        "4 5 3 1 6 2 \n"
        "1 6 5 3 2 4 \n"
        "6 5 2 1 4 3 \n";

    ASSERT_EQ ( output , expectedResult );

    testSolver.changeNuts(values);
    testing::internal::CaptureStdout();
    testSolver.printNuts();
    output = testing::internal::GetCapturedStdout();
    expectedResult = 
        "Nuts: \n"
        "1 2 3 4 5 6 \n"
        "1 2 3 4 5 6 \n"
        "1 2 3 4 5 6 \n"
        "0 0 0 0 0 0 \n"
        "1 2 3 4 5 6 \n"
        "1 2 3 4 5 6 \n"
        "1 2 3 4 5 6 \n";

    ASSERT_EQ ( output , expectedResult );
}

TEST_F(TestSolver, PrintSolution) 
{    
    GameSolver testSolver; 
    testSolver.start();
    testing::internal::CaptureStdout();
    testSolver.printSolution();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expectedResult = 
        "Solution: \n";

    ASSERT_EQ ( output , expectedResult );
}