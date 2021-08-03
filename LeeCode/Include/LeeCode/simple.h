//
// Created by wxm_e on 2021/7/30.
//

#ifndef C_CPP_SIMPLE_H
#define C_CPP_SIMPLE_H

#include <vector>
using namespace std;

class SimpleSolution {
  public:
    /*
        剑指 Offer 03. 数组中重复的数字

        在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

        示例 1：
        输入：
        [2, 3, 1, 0, 2, 5, 3]
        输出：2 或 3
        限制：
        2 <= n <= 100000
        https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
    */
    int findRepeatNumber(std::vector<int>& nums);

    /**
     * 455 分发饼干 https://leetcode-cn.com/problems/assign-cookies/
     * @param g 胃口值
     * @param s 饼干大小
     * @return 能满足的最多孩子数
     * 贪心算法
     * 核心思想：把最小的饼干分给饥饿度最小的孩子，从而满足最多数量的孩子
     */
    int findContentChildren(vector<int>& g, vector<int>& s);
};

#endif // C_CPP_SIMPLE_H
