//
// Created by wxm_e on 2021/7/29.
//
#include "LeeCode/32_h_longestValidParentheses.h"
#include "LeeCode/hard.h"
#include "LeeCode/middle.h"
#include "LeeCode/simple.h"
#include "Utils/TimingTest.h"
#include "gtest/gtest.h"
#include "LeeCode/1_s_twoSums.h"

using namespace std;

namespace {
class LeeCodeSimpleTest : public TimingTest {
};
class LeeCodeMiddleTest : public TimingTest {
};
class LeeCodeHardTest : public TimingTest {
};

TEST_F(LeeCodeSimpleTest, findRepeatNumber)
{
    SimpleSolution solution;
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3, 4, 3, 0};
    int ans          = 0;
    ans              = solution.findRepeatNumber(nums);
    cout << ans << endl;
    GTEST_ASSERT_TRUE(ans == 2 || ans == 3);
}

TEST_F(LeeCodeMiddleTest, longestPalindrome)
{
    MiddleSolution solution;
    string res = "";
    res        = solution.longestPalindrome("babad");
    cout << res << endl;
    GTEST_ASSERT_TRUE(res == "bab" || res == "aba");

    res = solution.longestPalindrome("cbbd");
    cout << res << endl;
    ASSERT_STREQ("bb", res.c_str());

    ///测试暴力法找最长回文子串
    res = solution.longestPalindrome2("babad");
    cout << res << endl;
    GTEST_ASSERT_TRUE(res == "bab" || res == "aba");

    res = solution.longestPalindrome2("cbbd");
    cout << res << endl;
    ASSERT_STREQ("bb", res.c_str());
}

TEST_F(LeeCodeMiddleTest, findKthLargest)
{
    MiddleSolution solution;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int ans          = solution.findKthLargest(nums, 2);
    cout << ans << endl;
    GTEST_ASSERT_TRUE(ans == 5);
}

TEST_F(LeeCodeMiddleTest, findKthLargest2)
{
    MiddleSolution solution;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int ans          = solution.findKthLargest2(nums, 2);
    cout << ans << endl;
    GTEST_ASSERT_TRUE(ans == 5);
}

TEST_F(LeeCodeMiddleTest, minSubArrayLen)
{
    MiddleSolution solution;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int ans          = solution.minSubArrayLen(7, nums);
    cout << ans << endl;
    GTEST_ASSERT_TRUE(ans == 2);
}

TEST_F(LeeCodeMiddleTest, minSubArrayLen2)
{
    MiddleSolution solution;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int ans          = solution.minSubArrayLen2(7, nums);
    cout << ans << endl;
    GTEST_ASSERT_TRUE(ans == 2);
}

TEST_F(LeeCodeHardTest, firstMissingPostive)
{
    HardSolution solution;
    int ans;
    std::vector<int> v;
    v   = {1, 2, 0};
    ans = solution.firstMissingPositive(v);
    GTEST_ASSERT_EQ(3, ans);

    v   = {3, 4, -1, 1};
    ans = solution.firstMissingPositive(v);
    GTEST_ASSERT_EQ(2, ans);

    v   = {7, 8, 9, 11, 12};
    ans = solution.firstMissingPositive(v);
    GTEST_ASSERT_EQ(1, ans);
}

/// 贪心算法
TEST_F(LeeCodeSimpleTest, findContentChildren)
{
    SimpleSolution solution;
    vector<int> children = {1, 2, 3};
    vector<int> cookies  = {1, 1};
    int ans              = solution.findContentChildren(children, cookies);
    GTEST_ASSERT_EQ(1, ans);

    children = {1, 2};
    cookies  = {1, 2, 3};
    ans      = solution.findContentChildren(children, cookies);
    GTEST_ASSERT_EQ(2, ans);
}


TEST_F(LeeCodeSimpleTest, 1_hash)
{
    Solution_1_hash solution;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> expect = {0, 1};
    vector<int> ans;
    ans  = solution.twoSum(nums, target);
    GTEST_ASSERT_EQ(expect, ans);
}

TEST_F(LeeCodeHardTest, candy)
{
    HardSolution solution;
    vector<int> ratings = {1, 0, 2};
    int ans             = solution.candy(ratings);
    GTEST_ASSERT_EQ(5, ans);

    ratings = {1, 2, 2};
    ans     = solution.candy(ratings);
    GTEST_ASSERT_EQ(4, ans);

    ratings = {1, 3, 2, 2, 1};
    ans     = solution.candy(ratings);
    GTEST_ASSERT_EQ(7, ans);

    ratings = {1, 3, 4, 5, 2};
    ans     = solution.candy(ratings);
    GTEST_ASSERT_EQ(11, ans);
}

TEST_F(LeeCodeHardTest, 32_stack)
{
    Solution_32_stack solution;
    string s = ")()())";
    int ans  = solution.longestValidParentheses(s);
    GTEST_ASSERT_EQ(4, ans);

    s = "(()";
    ans  = solution.longestValidParentheses(s);
    GTEST_ASSERT_EQ(2, ans);

    s = "";
    ans  = solution.longestValidParentheses(s);
    GTEST_ASSERT_EQ(0, ans);
}

TEST_F(LeeCodeHardTest, 32_stack_2)
{
    Solution_32_stack2 solution;
    string s = ")()())";
    int ans  = solution.longestValidParentheses(s);
    GTEST_ASSERT_EQ(4, ans);

    s = "(()";
    ans  = solution.longestValidParentheses(s);
    GTEST_ASSERT_EQ(2, ans);

    s = "";
    ans  = solution.longestValidParentheses(s);
    GTEST_ASSERT_EQ(0, ans);
}

TEST_F(LeeCodeHardTest, 32_stack_dp)
{
    Solution_32_stack_and_dp solution;
    string s = ")()())";
    int ans  = solution.longestValidParentheses(s);
    GTEST_ASSERT_EQ(4, ans);

    s = "(()";
    ans  = solution.longestValidParentheses(s);
    GTEST_ASSERT_EQ(2, ans);

    s = "";
    ans  = solution.longestValidParentheses(s);
    GTEST_ASSERT_EQ(0, ans);
}

} // namespace