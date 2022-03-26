//
// Created by wxm on 2022/3/24.
//

#ifndef C_CPP_TREE_H
#define C_CPP_TREE_H

/**
 * 二叉查找树
 */
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef void *ElementType;

SearchTree SearchTree_makeEmpty(SearchTree tree);
Position SearchTree_find(SearchTree tree, ElementType val);
Position SearchTree_findMin(SearchTree tree);
Position SearchTree_findMax(SearchTree tree);
SearchTree SearchTree_insert(SearchTree tree, ElementType val);
SearchTree SearchTree_delete(SearchTree tree, ElementType val);
ElementType SearchTree_retrieve(Position p);

#endif // C_CPP_TREE_H
