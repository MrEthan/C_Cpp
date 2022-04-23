//
// Created by wxm on 2022/3/24.
//

#ifndef C_CPP_TREE_H
#define C_CPP_TREE_H

/**
 * 二叉查找树
 */
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType; // 定义成int仅是为了测试方便，实际一般为void *

typedef struct TreeNode {
    ElementType element;
    SearchTree left;
    SearchTree right;
} TreeNode;

SearchTree SearchTree_makeEmpty(SearchTree tree);
Position SearchTree_find(SearchTree tree, ElementType val);
Position SearchTree_findMin(SearchTree tree);
Position SearchTree_findMax(SearchTree tree);
SearchTree SearchTree_insert(SearchTree tree, ElementType val);
SearchTree SearchTree_delete(SearchTree tree, ElementType val);
ElementType SearchTree_retrieve(Position p);
void SearchTree_print(SearchTree tree);

#endif // C_CPP_TREE_H
