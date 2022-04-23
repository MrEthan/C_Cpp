//
// Created by wxm_e on 2022/4/23.
//
#include "Algorithms/bfs.h"
#include "Algorithms/tree.h"
#include "Utils/TimingTest.h"
#include "gtest/gtest.h"
#include <iostream>

SearchTree tree = nullptr;
int nums[]      = {8, 4, 10, 1, 2};

namespace {
class bfsTest : public TimingTest {
    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
  protected:
    void SetUp() override
    {
        /**
         *       8
         *      / \
         *     4  10
         *    / \
         *   1   2
         */
        for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
            tree = SearchTree_insert(tree, nums[i]);
        }
    }

    void TearDown() override
    {
        SearchTree_makeEmpty(tree);
    }

  private:
    // 定义测试要用的变量
};

TEST_F(bfsTest, caseDfs)
{
    SearchTree_print(tree);
    printf("\n");
    dfs(tree);
}
} // namespace