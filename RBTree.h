#pragma once
#include <iostream>
#include "TreeNode.h"

class RBTree
{
    TreeNode *root;

    TreeNode *rotateLL(TreeNode *curr);
    TreeNode *rotateLR(TreeNode *curr);
    TreeNode *rotateRL(TreeNode *curr);
    TreeNode *rotateRR(TreeNode *curr);
    TreeNode *_insert(TreeNode *curr, TreeNode *ptr);
    int predecessor(TreeNode *curr) const;
    // TreeNode *_erase(TreeNode *curr, const int &val);
    void preorder(TreeNode *curr) const;
    void inorder(TreeNode *curr) const;

public:
    RBTree();
    void insert(const int &val);
    // void erase(const int &val);
    void describe() const;
};