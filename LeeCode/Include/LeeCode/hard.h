//
// Created by wxm_e on 2021/7/30.
//

#ifndef C_CPP_HARD_H
#define C_CPP_HARD_H

#include <vector>

class HardSolution {
  public:
    /*
        https://leetcode-cn.com/problems/first-missing-positive/
        给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
        示例 1:
        输入: [1,2,0]
        输出: 3

        示例 2:
        输入: [3,4,-1,1]
        输出: 2

        示例 3:
        输入: [7,8,9,11,12]
        输出: 1

        提示：
        你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。
    */
    int firstMissingPositive(std::vector<int> &nums);
};

#endif // C_CPP_HARD_H
