//
// Created by wxm_e on 2021/7/30.
//
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include "LeeCode/hard.h"

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

/*
int main(char argc, char** argv) {
    Solution solution;
    vector<int> v = { 1,2,0 };
    int ans = solution.firstMissingPositive(v);
    cout << ans << endl;
    return 0;
}
*/