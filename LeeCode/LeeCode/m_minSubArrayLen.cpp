#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
209. 长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。

示例: 
输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum
*/

/*
//暴力法 O(n^2)
class Solution {
private:
	// 计算连续数组和大于s的最小长度 
	int calcSumSize(int s, vector<int>& nums, int idx) {
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

public:
	int minSubArrayLen(int s, vector<int>& nums) {
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
};
*/


//双指针实现队列 O(n)
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int ans = INT_MAX, head = 0, tail = 0, sum = 0;
		int n = nums.size();

		while (head < n) {
			//头入队列
			sum += nums[head++];
			//尾出队列
			while (sum >= s) {
				ans = min(ans, (head - 1) - tail + 1);
				//cout << "head:tail " << head << ':' << tail << "sum:" << sum << "ans:" << ans << endl;
				sum -= nums[tail++];
			}
		}

		return ans == INT_MAX? 0:ans;
	}
};

/*
int main(int argc, char** argv) {
	Solution solution;
	vector<int> nums = { 4,3 };
	int ans = 0;
	ans = solution.minSubArrayLen(7, nums);
	cout << endl << ans << endl;
	return 0;
}
*/	