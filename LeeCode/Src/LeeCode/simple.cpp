//
// Created by wxm_e on 2021/7/30.
//

#include "LeeCode/simple.h"
#include <set>

int SimpleSolution::findRepeatNumber(std::vector<int> &nums)
{
    std::set<int> set;
    int ans = -1;

    for (auto it = nums.begin(); it != nums.end(); it++) {
        auto ret = set.insert(*it);
        if (ret.second != true) {
            ans = *it;
            break;
        }
    }
    return ans;
}