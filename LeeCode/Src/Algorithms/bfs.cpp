//
// Created by wxm_e on 2022/4/23.
//

#include "Algorithms/bfs.h"
#include "Algorithms/tree.h"
#include <cstdio>

ElementType process(Position p)
{
    int val = SearchTree_retrieve(p);
    printf("%d ", val);
    return val;
}

/**
 * 二叉树深度优先遍历 根左右，先序遍历
 * @param tree
 */
void dfs(SearchTree tree)
{
    if (nullptr == tree) {
        return ;
    }
    process(tree);
    dfs(tree->left);
    dfs(tree->right);
}
