//
// Created by wxm_e on 2022/3/26.
//

#include "Algorithms/tree.h"
#include "Utils/TimingTest.h"
#include "gtest/gtest.h"
#include <iostream>

namespace {
class treeTest : public TimingTest {
    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
  protected:
    void SetUp() override
    {
        printf("treeTest run SetUp\n");
    }

    void TearDown() override
    {
        printf("treeTest run teardown\n");
    }

  public:
    static void SetUpTestSuite()
    {
        printf("treeTest run SetUpTestSuite\n");
    }
    static void TearDownTestSuite()
    {
        printf("treeTest run TearDownTestSuite\n");
    }

  private:
    // 定义测试要用的变量
};

TEST_F(treeTest, searchTree)
{
    printf("run searchTree test\n");
    SearchTree tree = nullptr;
    int nums[]      = {4, 5, 2, 0, 2, 1, 9};
    // 创建
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        tree = SearchTree_insert(tree, nums[i]);
    }
    // 输出排序结果
    SearchTree_print(tree);
    Position p_max =  SearchTree_findMax(tree);
    Position p_min = SearchTree_findMin(tree);
    GTEST_ASSERT_EQ(9, SearchTree_retrieve(p_max));
    GTEST_ASSERT_EQ(0, SearchTree_retrieve(p_min));
    // 删除节点
    SearchTree_delete(tree, 0);
    SearchTree_delete(tree, 9);
    p_max =  SearchTree_findMax(tree);
    p_min = SearchTree_findMin(tree);
    GTEST_ASSERT_EQ(5, SearchTree_retrieve(p_max));
    GTEST_ASSERT_EQ(1, SearchTree_retrieve(p_min));
    printf("\n");
    SearchTree_print(tree);
    // 销毁
    SearchTree_makeEmpty(tree);
}

TEST_F(treeTest, buildTree2)
{
    printf("run buildTree2\n");
}

} // namespace