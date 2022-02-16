//
// Created by wxm on 2022/2/15.
//

#ifndef C_CPP_32_H_LONGESTVALIDPARENTHESES_H
#define C_CPP_32_H_LONGESTVALIDPARENTHESES_H

#include <string>
using namespace std;

// https://leetcode-cn.com/problems/longest-valid-parentheses/
int longestValidParentheses(string s);
class Solution_32 {
  public:
    virtual int longestValidParentheses(string s) = 0;
};

class Solution_32_stack : Solution_32 {
  public:
    int longestValidParentheses(string s) override;
};

class Solution_32_stack2 : Solution_32 {
  public:
    int longestValidParentheses(string s) override;
};

#endif // C_CPP_32_H_LONGESTVALIDPARENTHESES_H
