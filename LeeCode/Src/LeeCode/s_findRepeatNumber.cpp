#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

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

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		set<int> set;
		int ans = -1;

		for (auto it = nums.begin(); it != nums.end(); it++) {
			auto ret = set.insert(*it);
			if (ret.second != true){
				ans = *it;
				break;
			}
		}
		return ans;
	}
};

/*
int main(int argc, char** argv) {
	Solution solution;
	vector<int> nums = { 2, 3, 1, 0, 2, 5, 3 };
	int ans = 0;
	ans = solution.findRepeatNumber(nums);
	cout << ans << endl;
	return 0;
}
*/