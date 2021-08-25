//
// Created by wxm_e on 2021/7/30.
//

#ifndef C_CPP_HARD_H
#define C_CPP_HARD_H

#include <vector>
using namespace std;

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
    int firstMissingPositive(vector<int> &nums);

    /**
     * @brief 135. 分发糖果 https://leetcode-cn.com/problems/candy/\n
     * N个孩子站成一排，根据孩子的评分分发糖果\n
     * 1. 每个孩子至少分到1颗糖果\n
     * 2. 评分更高的孩子比他相邻两侧的孩子分到更多的糖果\n
     * 示例： 输入[1,0,2] 输出5, 分别分发2,1,2颗糖果\n
     *       输入[1,2,2] 输出4，分别分发1,2,1颗糖果\n
     * @param ratings
     * @return 最少需要的糖果数
     * 贪心算法
     */
    int candy(vector<int>& ratings);
};

#endif // C_CPP_HARD_H
