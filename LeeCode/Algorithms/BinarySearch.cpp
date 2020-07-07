﻿#include <iostream>
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

#pragma region 33. M 搜索旋转排序数组
	/*
		假设按照升序排序的数组在预先未知的某个点上进行了旋转。
		( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

		搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

		你可以假设数组中不存在重复的元素。

		你的算法时间复杂度必须是 O(log n) 级别。

		示例 1:

		输入: nums = [4,5,6,7,0,1,2], target = 0
		输出: 4
		示例 2:

		输入: nums = [4,5,6,7,0,1,2], target = 3
		输出: -1

		来源：力扣（LeetCode）
		链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array
		著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
	*/
	//https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/er-fen-fa-python-dai-ma-java-dai-ma-by-liweiwei141/
	//根据数组中间节点、target、right关系，逐步缩小查找区间
	int searchRotateArray(vector<int>& nums, int target) {
		int size = nums.size();
		int left = 0, right = size - 1;

		if (size <= 0) {
			return -1;
		}

		while (left < right) {
			int mid = left + (right - left + 1) / 2; //出现left=mid即使用上边界,必须在上面的 mid 表达式的括号里 + 1
			
			if (nums[mid] < nums[right]) {
				//右侧有序
				if (nums[mid] <= target && target <= nums[right]) {
					//target处于右侧有序区间，缩小查询范围为[mid,right]
					left = mid;
				}
				else {
					//target不在右侧有序区间，就在左侧区间 [left,mid-1]
					right = mid - 1;
				}
			}
			else {
				// [left, mid] 有序，但是为了和上一个 if 有同样的收缩行为，
			    // 我们故意只认为 [left, mid - 1] 有序
			    // 当区间只有 2 个元素的时候 int mid = (left + right + 1) >>> 1; 一定会取到右边
			    // 此时 mid - 1 不会越界，就是这么刚刚好
				if (nums[left] <= target && target <= nums[mid - 1]) {
					//target处于左侧有序区间，缩小查询范围为[left,mid-1]
					right = mid - 1;
				}
				else {
					left = mid;
				}
			}
		}
		// 有可能区间内不存在目标元素，因此还需做一次判断
		if (nums[left] == target) {
			return left;
		}

		return -1;
	}
#pragma endregion
#pragma region 153. 寻找旋转排序数组中的最小值
	//暴力法 O(n)
	int findMin0(vector<int>& nums) {
		int size = nums.size();
		int min = INT_MAX;
		for (int i = 0; i < size; i++) {
			if (nums[i] < min) {
				min = nums[i];
			}
		}
		return min;
	}
#pragma endregion

};

int main(char argc, char** argv) {
	vector<int> nums = { };
	BinarySearch b;
	int res = b.searchRotateArray(nums, 2);
	cout << res << endl;
	//cout << res[0] << ',' << res[1] << endl;
	
	return 0;
}