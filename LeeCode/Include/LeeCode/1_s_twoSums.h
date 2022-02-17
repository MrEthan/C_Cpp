//
// Created by wxm on 2022/2/17.
//

#ifndef C_CPP_1_S_TWOSUMS_H
#define C_CPP_1_S_TWOSUMS_H

#include <vector>
using namespace std;

class Solution_1 {
  public:
    virtual vector<int> twoSum(vector<int>& nums, int target) = 0;
};

class Solution_1_hash:Solution_1 {
  public:
    vector<int> twoSum(vector<int>& nums, int target) override;
};
#endif // C_CPP_1_S_TWOSUMS_H
