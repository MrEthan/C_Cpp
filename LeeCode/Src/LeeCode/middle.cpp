//
// Created by wxm_e on 2021/7/30.
//
#include "LeeCode/middle.h"
#include <algorithm>
#include <climits>
#include <vector>
#include <iostream>

using namespace std;

int MiddleSolution::partition(vector<int> &nums, int left, int right)
{
    int pivot = nums[left];
    int j     = left;

    for (int i = left + 1; i <= right; i++) {
        if (nums[i] < pivot) {
            // 小于 pivot 的元素都被交换到前面
            j++;
            swap(nums, j, i);
        }
    }
    // 在之前遍历的过程中，满足 [left + 1, j] < pivot，并且 (j, i] >= pivot
    swap(nums, j, left);
    // 交换以后 [left, j - 1] < pivot, nums[j] = pivot, [j + 1, right] >= pivot
    return j;
}

void MiddleSolution::swap(vector<int> &nums, int index1, int index2)
{
    int temp     = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = temp;
}

string MiddleSolution::longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    string ans = s.substr(0, 1);
    int maxLen = 1;
    int i = 0, j = 0;

    for (i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (j = 1; j < n; j++) {
        for (i = 0; i < j; i++) {
            if (s[i] != s[j]) {
                dp[i][j] = 0;
            } else {
                if (((j - 1) - (i + 1) + 1) < 2) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j] == 1) {
                    if (maxLen < j - i + 1) {
                        maxLen = j - i + 1;
                        ans    = s.substr(i, j - i + 1);
                    }
                }
            }
        }
    }
    return ans;
}

bool MiddleSolution::validPalindrome(string s, int left, int right)
{
    //验证子串s[left,right]是否为回文串
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

string MiddleSolution::longestPalindrome2(string s)
{
    int size = s.size();
    if (size < 2) {
        return s;
    }

    int maxLen = 1, maxLeft = 0, maxRight = 1;
    string res = s.substr(0, 1);
    string temp;
    int left = 0, right = 0;
    for (left = 0; left < size - 1; left++) {
        for (right = left + 1; right < size; right++) {
            if ((maxLen < right - left + 1) && (true == validPalindrome(s, left, right))) {
                maxLen   = right - left + 1;
                maxLeft  = left;
                maxRight = right;
            }
        }
    }
    if (maxLen > 1) {
        return s.substr(maxLeft, maxRight - maxLeft + 1);
    } else {
        return res;
    }
}

int MiddleSolution::findKthLargest2(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end(), greater<int>());
    int ans = nums[k - 1];
    return ans;
}

int MiddleSolution::findKthLargest(vector<int> &nums, int k)
{
    int len   = nums.size();
    int left  = 0;
    int right = len - 1;

    // 转换一下，第 k 大元素的索引是 len - k
    int target = len - k;

    while (true) {
        int index = partition(nums, left, right);
        if (index == target) {
            return nums[index];
        } else if (index < target) {
            left = index + 1;
        } else {
            right = index - 1;
        }
    }
}

int MiddleSolution::minSubArrayLen(int s, vector<int> &nums)
{
    int ans = INT_MAX, head = 0, tail = 0, sum = 0;
    int n = nums.size();

    while (head < n) {
        //头入队列
        sum += nums[head++];
        //尾出队列
        while (sum >= s) {
            ans = min(ans, (head - 1) - tail + 1);
            // cout << "head:tail " << head << ':' << tail << "sum:" << sum << "ans:" << ans << endl;
            sum -= nums[tail++];
        }
    }

    return ans == INT_MAX ? 0 : ans;
}

int MiddleSolution::minSubArrayLen2(int s, vector<int>& nums) {
    int min = 0, count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        count = calcSumSize(s, nums, i);
        if (count > 0 && (count < min || min == 0)) {
            min = count;
        }
    }
    return min;
}

// 计算连续数组和大于s的最小长度
int MiddleSolution::calcSumSize(int s, vector<int>& nums, int idx) {
    int count = 0;
    int sum = 0;

    cout << "idx:" << idx << endl;
    for (int i = idx; i < (int)nums.size(); i++) {
        sum += nums[i];
        count++;
        if (sum >= s) {
            cout <<"count:"<< count << endl;
            break;
        }
    }

    if (sum < s) {
        count = 0;
    }

    return count;
}