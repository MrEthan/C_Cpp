//
// Created by wxm_e on 2021/7/30.
//

#ifndef C_CPP_MIDDLE_H
#define C_CPP_MIDDLE_H

#include <string>
#include <vector>

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

    /*
    215.数组中的第K个最大元素
    在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

    示例 1:
    输入: [3,2,1,5,6,4] 和 k = 2
    输出: 5

    示例2:
    输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
    输出: 4
    说明:你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

    链接：https://leetcode-cn.com/problems/kth-largest-element-in-an-array
    */
    int findKthLargest(std::vector<int> &nums, int k);
    /**
     * 暴力解法，先按从大到小排序，再取第k个数
     * @param nums
     * @param k
     * @return
     */
    int findKthLargest2(std::vector<int> &nums, int k);

    /*
    209. 长度最小的子数组
    给定一个含有n个正整数的数组和一个正整数s ，找出该数组中满足其和 ≥ s
    的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。

    示例:
    输入: s = 7, nums = [2,3,1,2,4,3]
    输出: 2
    解释: 子数组[4,3]是该条件下的长度最小的连续子数组。
    进阶:

    如果你已经完成了O(n) 时间复杂度的解法, 请尝试O(n log n) 时间复杂度的解法。

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum
    */
    int minSubArrayLen(int s, std::vector<int> &nums);  // 双指针实现 O(n)
    int minSubArrayLen2(int s, std::vector<int> &nums); // 暴力法

  private:
    bool validPalindrome(std::string s, int left, int right);
    /**
     * 在数组 nums 的子区间 [left, right] 执行 partition 操作，返回 nums[left] 排序以后应该在的位置
     * 在遍历过程中保持循环不变量的语义
     * 1、[left + 1, j] < nums[left]
     * 2、(j, i] >= nums[left]
     *
     * @param nums
     * @param left
     * @param right
     * @return
     */
    int partition(std::vector<int> &nums, int left, int right);
    void swap(std::vector<int> &nums, int index1, int index2);

    int calcSumSize(int s, std::vector<int> &nums, int idx);
};

#endif // C_CPP_MIDDLE_H
