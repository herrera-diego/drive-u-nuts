#include "gtest/gtest.h"
#include <string>

#include <stdio.h>
#include <unistd.h>

#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include "nut.h"

using namespace DriveYaNuts;
using namespace std;

class TestNut : public testing::Test 
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

TEST_F(TestNut, InitialSide) 
{
    int values[6] = {1,2,3,4,5,6};
    Nut testNut (values);
    ASSERT_EQ ( testNut.getCurrentSide(), 1 );
}

TEST_F(TestNut, GetLeft) 
{
    int values[6] = {1,2,3,4,5,6};
    Nut testNut (values);
    ASSERT_EQ ( testNut.getCurrentSide(), 1 );
    ASSERT_EQ ( testNut.getLeftSide(), 6 );
    ASSERT_EQ ( testNut.getCurrentSide(), 1 );
}

TEST_F(TestNut, GetRight) 
{
    int values[6] = {1,2,3,4,5,6};
    Nut testNut (values);
    ASSERT_EQ ( testNut.getCurrentSide(), 1 );
    ASSERT_EQ ( testNut.getRightSide(), 2 );
    ASSERT_EQ ( testNut.getCurrentSide(), 1 );
}


TEST_F(TestNut, RotateLeft) 
{
    int values[6] = {1,2,3,4,5,6};
    Nut testNut (values);
    ASSERT_EQ ( testNut.getCurrentSide(), 1 );
    ASSERT_EQ ( testNut.rotateLeft(), 6 );
    ASSERT_EQ ( testNut.getCurrentSide(), 6 );
}

TEST_F(TestNut, RotateRight) 
{
    int values[6] = {1,2,3,4,5,6};
    Nut testNut (values);
    ASSERT_EQ ( testNut.getCurrentSide(), 1 );
    ASSERT_EQ ( testNut.rotateRight(), 2 );
    ASSERT_EQ ( testNut.getCurrentSide(), 2 );
}


TEST_F(TestNut, PrintValues) 
{
    int values[6] = {1,2,3,4,5,6};
    Nut testNut (values);
    testing::internal::CaptureStdout();
    testNut.printValues();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ ( output, "1 2 3 4 5 6 \n" );
   
}


TEST_F(TestNut, GetValues) 
{
    int values[6] = {1,2,3,4,5,6};
    Nut testNut (values);
    
    int expValues[6] = {0,0,0,0,0,0};
    testNut.getValues(expValues);
    
    bool comparisson = true;
    for (size_t i = 0; i < 6; i++)
    {
        if(values[i] != expValues[i])
        {
            comparisson = false;
            break;
        }
    }
    
    ASSERT_TRUE (comparisson);
   
}

TEST_F(TestNut, EqualComparisson) 
{
    int values1[6] = {1,2,3,4,5,6};
    Nut testNut1 (values1);
    
    int values2[6] = {1,2,3,4,5,6};
    Nut testNut2 (values2);
        
    ASSERT_TRUE (testNut1 == testNut2);

    int values3[6] = {1,2,3,5,4,6};
    Nut testNut3 (values3);

    ASSERT_FALSE (testNut1 == testNut3);
   
}


TEST_F(TestNut, CompareSides) 
{
    int valuesCenter[6] = {4,5,3,1,6,2};
    Nut testCenter (valuesCenter);
    
    int values1[6] = {4,6,2,3,5,1};
    Nut testNut1 (values1);
        
    ASSERT_TRUE (testCenter.compareSides(testNut1));

    int values2[6] = {4,5,3,2,6,1};
    Nut testNut2 (values2);
        
    ASSERT_FALSE (testCenter.compareSides(testNut2));

    int values3[6] = {4,6,3,1,5,2};
    Nut testNut3 (values3);
        
    ASSERT_FALSE (testCenter.compareSides(testNut3));

    int values4[6] = {5,4,3,1,2,6};
    Nut testNut4 (values4);
        
    ASSERT_FALSE (testCenter.compareSides(testNut4));
}
