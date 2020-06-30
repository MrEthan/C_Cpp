#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //ѡ������ÿһ��ɨ���ҵ�һ����СԪ��
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

    //�ݹ�ʵ�ֹ鲢����
    void mergeSort(vector<int>& nums, int left, int right) {
        int n = nums.size();
        //mid = (left + right)/2 ��left��rightΪ����ʱ�����ܵ������
        int mid = left + (right - left) / 2;

        //�ݹ��������
        if (left >= right) {
            return;
        }

        //�鲢������ [left, mid] [mid+1, right]
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        //�ϲ���������
        mergeTwoSortedArray(nums, left, mid, right);
        return ;
    }

    //��������
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
        //����ԭ����
        for (int i = 0; i < length; i++) {
            //temp[i] = nums[left + i];
            temp.push_back(nums[left + i]);
            cout << nums[i] << ',';
        }
        cout << endl;
        //��������ʼ�±�
        int l = 0;
        //��������ʼ�±�
        int r = mid - left + 1;

        for (int i = 0; i < length; i++) {
            //����������Ѿ����꣬��������Ҳ�����
            if (l > mid - left) {
                nums[i + left] = temp[r];
                r++;
            }
            //����������Ѿ����꣬��������������
            else if (r > length - 1) {
                nums[i + left] = temp[l];
                l++;
            }
            //ѡ�������Ҳ��С�����鸴��
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
    
    //��������
    void quick_sort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int pivot = partition(nums, left, right);
            quick_sort(nums, left, pivot);
            quick_sort(nums, pivot + 1, right);
        }
        return;
    }

    //���������㷨
    int partition(vector<int>& nums, int left, int right) {
        //�ų���������Ӱ�죬�絹�����飬���ѡȡ�ο�ֵ
        int randIndex = rand() % (right - left + 1) + left;
        swap(nums, left, randIndex);

        int pivot = left;
        int mid = nums[left];
        
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] < mid) {
                //����������ӿ�λ���ѱȲο���С��ֵ�ƶ����������
                pivot++;
                swap(nums, i, pivot);
            }
        }
        //�Ѳο����ֵ�������ο��±�λ��
        swap(nums, left, pivot);
        return pivot;
    }
};

int main(char argc, char** argv) {
    Solution solution;
    vector<int> v = { 4,3,5,6,2,-1,0,-2,4 };
    cout << "�鲢����" << endl;
    solution.mergeSort(v, 0, v.size() - 1);
    for (auto e : v) {
        cout << e << ' ';
    }
    cout << "��������" << endl;
    solution.quickSort(v);
    for (auto e : v) {
        cout << e << ' ';
    }
    return 0;
}
