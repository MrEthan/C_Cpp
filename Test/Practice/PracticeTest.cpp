//
// Created by wxm_e on 2021/7/29.
//
#include "Utils/TimingTest.h"
#include "my_smart_ptr.h"
#include "gtest/gtest.h"

using namespace std;

namespace practiceTest {

class PracticeTest : public TimingTest {
};

TEST_F(PracticeTest, smart_ptr)
{
    int ret = practice::smart_ptr();
    GTEST_ASSERT_EQ(0, ret);
}

} // namespace practiceTest