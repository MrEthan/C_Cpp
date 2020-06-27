#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

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

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (unsigned int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > (int)nums.size() || nums[i] == nums[nums[i] - 1]) {
                    break;
                }
                /* 把nums[i]与i-1下标元素交换 */
                int idx = nums[i] - 1;
                nums[i] = nums[idx];
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
};

/*
int main(char argc, char** argv) {
    Solution solution;
    vector<int> v = { 1,2,0 };
    int ans = solution.firstMissingPositive(v);
    cout << ans << endl;
    return 0;
}
*/