#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

/*
https://leetcode-cn.com/problems/first-missing-positive/
����һ��δ������������飬�����ҳ�����û�г��ֵ���С����������

ʾ�� 1:

����: [1,2,0]
���: 3
ʾ�� 2:

����: [3,4,-1,1]
���: 2
ʾ�� 3:

����: [7,8,9,11,12]
���: 1

��ʾ��

����㷨��ʱ�临�Ӷ�ӦΪO(n)������ֻ��ʹ�ó�������Ķ���ռ䡣
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (unsigned int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > (int)nums.size() || nums[i] == nums[nums[i] - 1]) {
                    break;
                }
                /* ��nums[i]��i-1�±�Ԫ�ؽ��� */
                int idx = nums[i] - 1;
                nums[i] = nums[idx];
                nums[idx] = idx + 1;
            }
        }
        int ans = nums.size() + 1;
        /* ��������,��һ�����±겻��ȵ�����Ԫ�أ���Ϊȱʧ����С������ */
        for (unsigned int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                ans = i + 1;
                break;
            }
        }

        return ans;
    }
};

/*
int main(char argc, char** argv) {
    Solution solution;
    vector<int> v = { 1,2,0 };
    int ans = solution.firstMissingPositive(v);
    cout << ans << endl;
    return 0;
}
*/