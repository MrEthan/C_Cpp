#include <vector>
using namespace std;

class BinarySearch {
  public:
    /*
    34. M 在排序数组中查找元素的第一个和最后一个位置
    给定一个按照升序排列的整数数组 nums，和一个目标值
    target。找出给定目标值在数组中的开始位置和结束位置。

    你的算法时间复杂度必须是 O(log n) 级别。
    如果数组中不存在目标值，返回 [-1, -1]。

    示例 1:
    输入: nums = [5,7,7,8,8,10], target = 8
    输出: [3,4]

    示例 2:
    输入: nums = [5,7,7,8,8,10], target = 6
    输出: [-1,-1]

    链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    */
    vector<int> searchRange(vector<int> &nums, int target);

    /*
    M.33 搜索旋转排序数组
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
    */
    // https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/er-fen-fa-python-dai-ma-java-dai-ma-by-liweiwei141/
    //根据数组中间节点、target、right关系，逐步缩小查找区间
    int searchRotateArray(vector<int> &nums, int target);
 
    /* 153. 寻找旋转排序数组中的最小值 */
    //暴力法 O(n)
    int findMin0(vector<int> &nums);
    //二分法
    int findMin1(vector<int> &nums);
};