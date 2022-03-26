//
// Created by wxm on 2022/3/24.
//

#include "Algorithms/tree.h"
#include <cstdlib>
#include <iostream>

struct TreeNode {
    ElementType element;
    SearchTree left;
    SearchTree right;
};

SearchTree SearchTree_makeEmpty(SearchTree tree)
{
    if (nullptr != tree) {
        SearchTree_makeEmpty(tree->left);
        SearchTree_makeEmpty(tree->right);
        delete (tree);
    }
    return nullptr;
}

Position SearchTree_find(SearchTree tree, ElementType val)
{
    if (nullptr == tree) {
        return nullptr;
    }

    if (val < tree->element) {
        return SearchTree_find(tree->left, val);
    } else if (val > tree->element) {
        return SearchTree_find(tree->right, val);
    } else {
        return tree;
    }
}

Position SearchTree_findMin(SearchTree tree)
{
    if (nullptr == tree) {
        return nullptr;
    }
    // 如果左子树为空，则根节点就是最小的节点
    if (tree->left == nullptr) {
        return tree;
    } else {
        // 最小节点肯定在左子树上
        return SearchTree_findMin(tree->left);
    }
}
Position SearchTree_findMax(SearchTree tree)
{
    if (tree == nullptr) {
        return nullptr;
    }

    // 如果右边子树为空，则根节点肯定是最大的节点
    if (tree->right == nullptr) {
        return tree;
    } else {
        // 最大的节点肯定在子树上
        return SearchTree_findMax(tree->right);
    }
}

// 插入新节点，并返回新树的根节点
SearchTree SearchTree_insert(SearchTree tree, ElementType val)
{
    // 如果为空，则新节点成为根节点
    if (tree == nullptr) {
        tree = (SearchTree)malloc(sizeof(TreeNode));
        if (tree == nullptr) {
            perror("malloc fail\n");
            return nullptr;
        }
        tree->element = val;
        tree->left = tree->right = nullptr;
        return tree;
    } else if (val < tree->element) {
        // 如果比根节点小，则插入左边
        tree->left = SearchTree_insert(tree->left, val);
    } else if (val > tree->element) {
        // 如果比根节点大，则插入右边
        tree->right = SearchTree_insert(tree->right, val);
    } else {
        // 如果相等，则什么也不做
        printf("node already existed\n");
    }

    return tree;
}
SearchTree SearchTree_delete(SearchTree tree, ElementType val)
{
    if (tree == nullptr) {
        printf("tree is empty\n");
        return nullptr;
    }
    // 如果小于根节点，则从左边查找
    // 如果大于根节点，则从右边查找
    // 如果待删除的节点有两个孩子，则用右子树的最小节点代替删除的节点
    // 如果待删除的节点只有一个孩子，则用其孩子接替他
}

ElementType SearchTree_retrieve(Position p)
{
    if (p == nullptr) {
        return nullptr;
    }
    return p->element;
}
