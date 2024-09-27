#ifndef _TREENODE_H_
#define _TREENODE_H_

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    int height; // required for AVLTree
    bool isRed; // required for RBTree

    TreeNode(const int &val);
};

#endif // _TREENODE_H_