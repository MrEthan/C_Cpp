//
// Created by wxm_e on 2021/7/30.
//
#include "LeeCode/hard.h"
#include <numeric>
#include <vector>

using namespace std;

int HardSolution::firstMissingPositive(vector<int> &nums)
{
    for (unsigned int i = 0; i < nums.size(); i++) {
        while (nums[i] != i + 1) {
            if (nums[i] <= 0 || nums[i] > (int)nums.size() || nums[i] == nums[nums[i] - 1]) {
                break;
            }
            /* 把nums[i]与i-1下标元素交换 */
            int idx   = nums[i] - 1;
            nums[i]   = nums[idx];
            nums[idx] = idx + 1;
        }
    }
    int ans = nums.size() + 1;
    /* 遍历数组,第一个与下标不相等的数组元素，即为缺失的最小正整数 */
    for (unsigned int i = 0; i < nums.size(); i++) {
        if (nums[i] != i + 1) {
            ans = i + 1;
            break;
        }
    }

    return ans;
}

/**
 * 贪心算法
 * 1.所有孩子初始化为1
 * 2.从左往右遍历，右边孩子如果比左边分高，则右边孩子的糖果为左边的+1
 * 3.从右往左遍历，左边孩子如果比右边分高，则左边孩子的糖果为右边+1，否则不变
 */
int HardSolution::candy(vector<int> &ratings)
{
    size_t size = ratings.size();
    vector<int> nums(size, 1);
    for (size_t i = 1; i < size; i++) {
        if (ratings[i] > ratings[i - 1]) {
            nums[i] = nums[i - 1] + 1;
        }
    }
    for (size_t i = size - 1; i > 0; i--) {
        if (ratings[i - 1] > ratings[i]) {
            nums[i - 1] = max(nums[i] + 1, nums[i - 1]);
        }
    }

    //    for (auto it = nums.begin(); it != nums.end(); it++) {
    //        cout << *it << ' ';
    //    }
    //    cout << endl;
    return accumulate(nums.begin(), nums.end(), 0);
}