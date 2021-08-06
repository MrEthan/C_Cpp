#include "Algorithms/BinarySearch.h"
#include <climits>
#include <iostream>

vector<int> BinarySearch::searchRange(vector<int> &nums, int target)
{
    //先找到在数组中出现的位置，然后再向两边查找最小和最大下标
    int size = nums.size();
    int left = 0, right = size - 1;
    vector<int> v = {-1, -1};
    int index     = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            index = mid;
            break;
        } else if (nums[mid] < target) {
            //目标值大于中点，落在右侧区间 [mid+1,right]
            left = mid + 1;
        } else {
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
        } else {
            break;
        }
    }
    //向右查找最大小标
    for (int i = index + 1; i <= size - 1; i++) {
        if (nums[i] == nums[index]) {
            max = i;
        } else {
            break;
        }
    }
    v[0] = min;
    v[1] = max;

    return v;
}

int BinarySearch::searchRotateArray(vector<int> &nums, int target)
{
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
                // target处于右侧有序区间，缩小查询范围为[mid,right]
                left = mid;
            } else {
                // target不在右侧有序区间，就在左侧区间 [left,mid-1]
                right = mid - 1;
            }
        } else {
            // [left, mid] 有序，但是为了和上一个 if 有同样的收缩行为，
            // 我们故意只认为 [left, mid - 1] 有序
            // 当区间只有 2 个元素的时候 int mid = (left + right + 1) >>> 1;
            // 一定会取到右边 此时 mid - 1 不会越界，就是这么刚刚好
            if (nums[left] <= target && target <= nums[mid - 1]) {
                // target处于左侧有序区间，缩小查询范围为[left,mid-1]
                right = mid - 1;
            } else {
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

int BinarySearch::findMin0(vector<int> &nums)
{
    int size = nums.size();
    int min  = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (nums[i] < min) {
            min = nums[i];
        }
    }
    return min;
}

//二分法
int BinarySearch::findMin1(vector<int> &nums)
{
    int size = nums.size();
    int min  = INT_MAX;

    if (nums[0] < nums[size - 1]) {
        return nums[0];
    }

    int left = 0, right = size - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[right]) {
            // mid中间值比右侧小，说明右侧递增，最小值肯定位于左侧区间[left, mid]
            right = mid;
        } else {
            // mid中间值比右侧大，说明旋转点在右侧区间，[mid+1,right]
            left = mid + 1;
        }
    }

    return nums[left];
}

// int main(char argc, char **argv) {
//  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
//  BinarySearch b;
//  int res = b.findMin1(nums);
//  cout << res << endl;
//  // cout << res[0] << ',' << res[1] << endl;
//
//  return 0;
//}