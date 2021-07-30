//
// Created by wxm_e on 2021/7/30.
//

#ifndef C_CPP_MIDDLE_H
#define C_CPP_MIDDLE_H

#include <string>

class MiddleSolution {
  public:
    /*
    最长回文子串
    给定一个字符串 s，找到 s 中最长的回文子串。你可以假设s 的最大长度为 1000。

    示例 1：
    输入: "babad"
    输出: "bab"
    注意: "aba" 也是一个有效答案。

    示例 2：
    输入: "cbbd"
    输出: "bb"
    */
    std::string longestPalindrome(std::string s); /// 动态规划法求最长回文子串
    /// 暴力法求最长回文子串
    std::string longestPalindrome2(std::string s);
  private:
    bool validPalindrome(std::string s, int left, int right);
};

#endif // C_CPP_MIDDLE_H
