#include <iostream>
#include <vector>
using namespace std;

class BinarySearch {
public:
#pragma region 34. M 在排序数组中查找元素的第一个和最后一个位置
	/*
	给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

	你的算法时间复杂度必须是 O(log n) 级别。

	如果数组中不存在目标值，返回 [-1, -1]。

	示例 1:
	输入: nums = [5,7,7,8,8,10], target = 8
	输出: [3,4]

	示例 2:
	输入: nums = [5,7,7,8,8,10], target = 6
	输出: [-1,-1]

	来源：力扣（LeetCode）
	链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
	著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
	*/
	vector<int> searchRange(vector<int>& nums, int target) {
		//先找到在数组中出现的位置，然后再向两边查找最小和最大下标
		int size = nums.size();
		int left = 0, right = size - 1;
		vector<int> v = { -1,-1 };
		int index = -1;

		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				index = mid;
				break;
			}else if (nums[mid] < target) {
				//目标值大于中点，落在右侧区间 [mid+1,right]
				left = mid + 1;
			}else {
				//目标值落在左侧区间
				right = mid - 1;
			}
		}

		if (-1 == index) {
			return v;
		}

		int min = index, max = index;
		//向左查找最小下标
		for (int i = index - 1; i >= 0; i--) {
			if (nums[i] == nums[index]) {
				min = i;
			}
			else {
				break;
			}
		}
		//向右查找最大小标
		for (int i = index + 1; i <= size - 1; i++) {
			if (nums[i] == nums[index]) {
				max = i;
			}
			else {
				break;
			}
		}
		v[0] = min;
		v[1] = max;

		return v;
	}
#pragma endregion

};

int main(char argc, char** argv) {
	vector<int> nums = { 5,7,7,8,8,10 };
	vector<int> res;
	BinarySearch b;
	res = b.searchRange(nums, 8);
	cout << res[0] << ',' << res[1] << endl;
	return 0;
}