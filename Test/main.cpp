//
// Created by wxm_e on 2021/7/29.
//

#include "gtest/gtest.h"
#include <iostream>

int main(int argc, char **argv)
{
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    //    testing::FLAGS_gtest_list_tests = true;
    // 过滤测试用例，等效于 ./gtester --gtest_filter=treeTest.*
    //    testing::FLAGS_gtest_filter = "treeTest.*";
    return RUN_ALL_TESTS();
}