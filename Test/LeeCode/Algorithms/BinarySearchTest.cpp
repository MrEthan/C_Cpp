//
// Created by wxm_e on 2021/7/29.
//

#include "Algorithms/BinarySearch.h"
#include "Utils/TimingTest.h"
#include "gtest/gtest.h"
#include <iostream>

namespace {
class BinarySearchTest : public TimingTest {
};

TEST_F(BinarySearchTest, searchRange)
{
    BinarySearch bs;
    vector<int> ans;
    vector<int> nums;
    int target;
    vector<int> expect;

    nums   = {5, 7, 7, 8, 8, 10};
    target = 8;
    ans    = bs.searchRange(nums, target);
    expect = {3, 4};
    GTEST_ASSERT_TRUE(ans == expect);

    nums   = {5, 7, 7, 8, 8, 10};
    target = 6;
    ans    = bs.searchRange(nums, target);
    expect = {-1, -1};
    GTEST_ASSERT_TRUE(ans == expect);
}

TEST_F(BinarySearchTest, findMin1)
{
    vector<int> nums;
    BinarySearch bs;
    int ans;

    nums    = {4, 5, 6, 7, 0, 1, 2};
    ans = bs.findMin1(nums);
    GTEST_ASSERT_EQ(0, ans);
}

} // namespace