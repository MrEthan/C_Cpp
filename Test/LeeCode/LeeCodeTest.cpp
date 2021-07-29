//
// Created by wxm_e on 2021/7/29.
//
#include "LeeCode/hard.h"
#include "LeeCode/middle.h"
#include "gtest/gtest.h"

namespace {
TEST(LeeCodeHardTest, firstMissingPostive)
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

TEST(LeeCodeMiddleTest, longestPalindrome)
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

} // namespace
