#pragma once
#include <iostream>
#include <algorithm>
#include "TreeNode.h"

class AVLTree
{
    TreeNode *root;

    int getHeight(TreeNode *curr) const;
    int getBalanceFactor(TreeNode *curr) const;
    void calcHeight(TreeNode *curr);
    TreeNode *rotateLL(TreeNode *curr);
    TreeNode *rotateLR(TreeNode *curr);
    TreeNode *rotateRL(TreeNode *curr);
    TreeNode *rotateRR(TreeNode *curr);
    TreeNode *balance(TreeNode *curr);
    TreeNode *_insert(TreeNode *curr, TreeNode *ptr);
    int predecessor(TreeNode *curr) const;
    TreeNode *_erase(TreeNode *curr, const int &val);
    void preorder(TreeNode *curr) const;
    void inorder(TreeNode *curr) const;

public:
    AVLTree();
    void insert(const int &val);
    void erase(const int &val);
    void describe() const;
};