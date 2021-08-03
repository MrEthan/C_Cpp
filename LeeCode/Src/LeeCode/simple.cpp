//
// Created by wxm_e on 2021/7/30.
//

#include "LeeCode/simple.h"
#include <algorithm>
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

int SimpleSolution::findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int child = 0, cookie = 0;
    while (child < g.size() && cookie < s.size()) {
        if (g[child] <= s[cookie]) {
            child++;
        }
        cookie++;
    }
    return child;
}