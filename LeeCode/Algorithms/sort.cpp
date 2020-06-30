#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //选择排序，每一轮扫描找到一个最小元素
    vector<int> selectSort(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[min_idx]) {
                    min_idx = j;
                }
            }
            swap(nums, i, min_idx);
        }

        return nums;
    }

    //递归实现归并排序
    void mergeSort(vector<int>& nums, int left, int right) {
        int n = nums.size();
        //mid = (left + right)/2 在left和right为大数时，可能导致溢出
        int mid = left + (right - left) / 2;

        //递归结束条件
        if (left >= right) {
            return;
        }

        //归并闭区间 [left, mid] [mid+1, right]
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        //合并有序区间
        mergeTwoSortedArray(nums, left, mid, right);
        return ;
    }

    //快速排序
    vector<int> quickSort(vector<int>& nums) {
        quick_sort(nums, 0, (int)nums.size() - 1);
        return nums;
    }

private:
    void swap(vector<int>& nums, int idx1, int idx2) {
        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
        return;
    }

    void mergeTwoSortedArray(vector<int>& nums, int left, int mid, int right) {
        int length = right - left + 1;
        //vector<int> temp(length, 0);
        vector<int> temp;
        //复制原数组
        for (int i = 0; i < length; i++) {
            //temp[i] = nums[left + i];
            temp.push_back(nums[left + i]);
            cout << nums[i] << ',';
        }
        cout << endl;
        //左数组起始下标
        int l = 0;
        //右数组起始下标
        int r = mid - left + 1;

        for (int i = 0; i < length; i++) {
            //如果左数组已经用完，则仅复制右侧数组
            if (l > mid - left) {
                nums[i + left] = temp[r];
                r++;
            }
            //如果右数组已经用完，则仅复制左侧数组
            else if (r > length - 1) {
                nums[i + left] = temp[l];
                l++;
            }
            //选择左侧和右侧较小的数组复制
            else if (temp[l] < temp[r]) {
                nums[i + left] = temp[l];
                l++;
            }
            else {
                nums[i + left] = temp[r];
                r++;
            }
        }
    }
    
    //快速排序
    void quick_sort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int pivot = partition(nums, left, right);
            quick_sort(nums, left, pivot);
            quick_sort(nums, pivot + 1, right);
        }
        return;
    }

    //基础分治算法
    int partition(vector<int>& nums, int left, int right) {
        //排除特殊数据影响，如倒序数组，随机选取参考值
        int randIndex = rand() % (right - left + 1) + left;
        swap(nums, left, randIndex);

        int pivot = left;
        int mid = nums[left];
        
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] < mid) {
                //左边区间增加空位，把比参考点小的值移动到左边区间
                pivot++;
                swap(nums, i, pivot);
            }
        }
        //把参考点的值交换到参考下标位置
        swap(nums, left, pivot);
        return pivot;
    }
};

int main(char argc, char** argv) {
    Solution solution;
    vector<int> v = { 4,3,5,6,2,-1,0,-2,4 };
    cout << "归并排序" << endl;
    solution.mergeSort(v, 0, v.size() - 1);
    for (auto e : v) {
        cout << e << ' ';
    }
    cout << "快速排序" << endl;
    solution.quickSort(v);
    for (auto e : v) {
        cout << e << ' ';
    }
    return 0;
}
