//
// Created by wxm on 2022/2/15.
//
#include "LeeCode/32_h_longestValidParentheses.h"
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

//用栈
//先找到所有可以匹配的索引号，然后找出最长连续数列
//例如：s = )(()())，我们用栈可以找到，
//位置 2 和位置 3 匹配，
//位置 4 和位置 5 匹配，
//位置 1 和位置 6 匹配，
//这个数组为：2,3,4,5,1,6 这是通过栈找到的，我们按递增排序！1,2,3,4,5,6
//找出该数组的最长连续数列的长度就是最长有效括号长度！
//所以时间复杂度来自排序：O(nlogn)O(nlogn)。
//接下来我们思考，是否可以省略排序的过程,在弹栈时候进行操作呢?
//直接看代码理解!所以时间复杂度为：O(n)O(n)。

int Solution_32_stack::longestValidParentheses(string s)
{
    stack<int> stk;
    vector<int> vec;

    for (int i = 0; i < s.length(); i++) {
        if (!stk.empty() && s[i] == ')') {
            vec.push_back(stk.top());
            vec.push_back(i);
            stk.pop();
        } else if (s[i] == '(') {
            stk.push(i);
        }
    }
    sort(vec.begin(), vec.end());
//    for (auto c : vec) {
//        cout << c << ' ';
//    }
//    cout << endl;
    // 从vec中查找最长的连续等差数列
    int max_len = 0, len = 0;
    if (vec.size() < 2) {
        return 0;
    }
    for (auto i = 0; i < vec.size() - 1; i++) {
        if (vec[i + 1] - vec[i] == 1) {
            len++;
//            cout << "i:" << i << " len:" << len << endl;
        } else {
            len = 0;
        }
        if (len > 0) {
            max_len = std::max(max_len, len + 1);
        }
    }
    return max_len;
}

/**
 * 栈实现优化
 * 栈底元素始终保持为 最后一个没有被匹配的右括号的下标
 * 对于每一个遇到的‘(’，将它的下标放入栈中
 * 对于每一个遇到的‘)’，我们先弹出栈顶元素表示匹配了当前右括号：
 *      如果栈为空，说明当前的右括号为没有被匹配的右括号，我们将其下标放入栈中来更新我们之前提到的「最后一个没有被匹配的右括号的下标」
 *      如果栈不为空，当前右括号的下标减去栈顶元素即为「以该右括号为结尾的最长有效括号的长度」
 * 我们从前往后遍历字符串并更新答案即可。
 * 需要注意的是，如果一开始栈为空，第一个字符为左括号的时候我们会将其放入栈中，这样就不满提及的「最后一个没有被匹配的右括号的下标」
 * 为了保持统一，我们在一开始的时候往栈中放入一个值为 -1 的元素。
 */
int Solution_32_stack2::longestValidParentheses(string s)
{
    int max_len = 0;
    stack<int> stk;
    vector<int> vec;

    stk.push(-1);

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();
            if (stk.empty()) {
                stk.push(i);
            } else {
                max_len = std::max(max_len, i - stk.top());
            }
        }
    }
    return max_len;
}
