#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
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

    //插入排序，把新数插入前面已经排好序的序列中
    vector<int> insertSort(vector<int>& nums) {
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            for (int j = i; j > 0; j--) {
                if (nums[j] < nums[j - 1]) {
                    swap(nums, j, j - 1);
                }
                else {
                    break;
                }
            }
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
            //cout << nums[i] << ',';
        }
        //cout << endl;
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
            //int pivot = partition(nums, left, right);
            //int pivot = partitionDouble(nums, left, right);
            int pivot = patitionDoublePointer(nums, left, right);
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

    //双路分治快速排序(挖坑填数法)
    //1、选取参考点，作为第一个坑
    //2、从右向左找比参考点小的数，放到左边的坑，同时，右边挖出一个新的坑
    //3、从左向右找比参考点大的数，放到右边的坑，同时，左边挖出一个新的坑
    //4、把参考点的值放入最后一个坑
    int partitionDouble(vector<int>& nums, int left, int right) {
        //排除特殊数据影响，如倒序数组，随机选取参考值
        int randIndex = rand() % (right - left + 1) + left;
        swap(nums, left, randIndex);

        int mid = nums[left];
        int i = left, j = right;

        while (i < j) {
            //从右开始，找到比mid小的数，填到左边的坑
            while ((i < j) && (nums[j] >= mid)) {
                j--;
            }
            if (i < j) {
                nums[i] = nums[j];
                i++;
            }
            while ((i < j) && (nums[i] <= mid)) {
                i++;
            }
            if (i < j) {
                nums[j] = nums[i];
                j--;
            }
        }

        nums[i] = mid;
        
        return i;
    }

    //双路快排之指针对撞
    int patitionDoublePointer(vector<int>& nums, int left, int right) {
        //排除特殊数据影响，如倒序数组，随机选取参考值
        int randIndex = rand() % (right - left + 1) + left;
        swap(nums, left, randIndex);

        int mid = nums[left];
        int lt = left + 1;
        int gt = right;
        //循环不变量
        //all in [left,lt) <= pivot
        //all in (gt, right] >= pivot
        while (true) {
            while (lt <= right && nums[lt] < mid) {
                lt++;
            }
            while (gt > left && nums[gt] > mid) {
                gt--;
            }

            if (lt >= gt) {
                break;
            }

            // 细节：相等的元素通过交换，等概率分到数组的两边
            swap(nums, lt, gt);
            lt++;
            gt--;
        }
        swap(nums, left, gt);
        return gt;
    }
};

int main(char argc, char** argv) {
    Solution solution;
    vector<int> v_init = { 4,3,5,6,2,-1,0,-2,4 };
    vector<int> v;
    const int max = 5;

    srand((unsigned int)time(NULL));
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < max; i++) {
        v_init.push_back(rand());
    }
    auto end = chrono::steady_clock::now();
    chrono::duration<double, micro> elapsed = end - start; // std::micro 表示以微秒为时间单位
    cout << "数据生成 " << "time: " << elapsed.count() << "us" << endl;

    v.assign(v_init.begin(), v_init.end());
    start = chrono::steady_clock::now();
    sort(v.begin(), v.end(), greater<int>());
    end = chrono::steady_clock::now();
    elapsed = end - start; // std::micro 表示以微秒为时间单位
    cout << "sort排序 " << "time: " << elapsed.count() << "us" << endl;

    v.assign(v_init.begin(), v_init.end());
    start = chrono::steady_clock::now();
    solution.selectSort(v);
    end = chrono::steady_clock::now();
    elapsed = end - start; // std::micro 表示以微秒为时间单位
    cout << "选择排序 " << "time: " << elapsed.count() << "us" << endl;

    v.assign(v_init.begin(), v_init.end());
    start = chrono::steady_clock::now();
    solution.insertSort(v);
    end = chrono::steady_clock::now();
    elapsed = end - start; // std::micro 表示以微秒为时间单位
    cout << "插入排序 " << "time: " << elapsed.count() << "us" << endl;

    v.assign(v_init.begin(), v_init.end());
    start = chrono::steady_clock::now();
    solution.mergeSort(v, 0, v.size() - 1);
    end = chrono::steady_clock::now();
    elapsed = end - start; // std::micro 表示以微秒为时间单位
    cout << "归并排序 " << "time: " << elapsed.count() << "us" << endl;

    v.assign(v_init.begin(), v_init.end());
    start = chrono::steady_clock::now();
    solution.quickSort(v);
    end = chrono::steady_clock::now();
    elapsed = end - start; // std::micro 表示以微秒为时间单位
    cout << "快速排序 " << "time: " << elapsed.count() << "us" << endl;

    return 0;
}
