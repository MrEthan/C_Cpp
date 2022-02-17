//
// Created by wxm on 2022/2/17.
//

#include "LeeCode/1_s_twoSums.h"
#include <unordered_map>

/**
 * hash,key是数值，val为下标
 * 遍历nums，根据target-nums[i]查找hash,如果找到则是答案
 * 如果找不到，则把key,val放入hash表
 * @param nums
 * @param target
 * @return
 */
vector<int> Solution_1_hash::twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> hash;

    for (auto i = 0; i < nums.size(); i++) {
        auto it = hash.find(target - nums[i]);
        if (it != hash.end()) {
            return {it->second, i};
        } else{
            hash.insert({nums[i], i});
        }
    }
    return {};
}