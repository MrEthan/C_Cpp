//
// Created by wxm on 2022/3/24.
//

#include "Algorithms/tree.h"
#include <cstdlib>
#include <iostream>

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
    TreeNode *tmpNode = nullptr;

    if (val < tree->element) {
        // 如果待删除的节点小于根节点，则肯定在左子树上
        tree->left = SearchTree_delete(tree->left, val);
    } else if (val > tree->element) {
        // 如果待删除的节点大于根节点，则肯定在右子树上
        tree->right = SearchTree_delete(tree->right, val);
    } else if (tree->left != nullptr && tree->right != nullptr) {
        // 如果待删除的节点有两个孩子，则用右子树的最小节点代替删除的节点（即把右子树的最小节点放到当前位置，删除右子树最小节点原先位置内容）
        tmpNode       = SearchTree_findMin(tree->right);
        tree->element = tmpNode->element;
        tree->right   = SearchTree_delete(tree->right, tmpNode->element);
    } else {
        // 如果待删除的节点只有一个孩子，则用其孩子接替他
        tmpNode = tree;
        if (tree->left == nullptr) {
            tree = tree->right;
        } else if (tree->right == nullptr) {
            tree = tree->left;
        }
        free(tmpNode);
    }

    return tree;
}

ElementType SearchTree_retrieve(Position p)
{
    if (p == nullptr) {
        return -1;
    }
    return p->element;
}

void SearchTree_print(SearchTree tree)
{
    if (tree == nullptr) {
        printf("tree is null\n");
        return;
    }
    // 左 根 右遍历，从小到大
    if (tree->left != nullptr) {
        SearchTree_print(tree->left);
    }
    printf("%d ", tree->element);
    if (tree->right != nullptr) {
        SearchTree_print(tree->right);
    }
}