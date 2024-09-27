#include "AVLTree.h"

int AVLTree::getHeight(TreeNode *curr) const
{
    if (!curr)
    {
        return 0;
    }
    return curr->height;
}

int AVLTree::getBalanceFactor(TreeNode *curr) const
{
    return getHeight(curr->left) - getHeight(curr->right);
}

void AVLTree::calcHeight(TreeNode *curr)
{
    curr->height = 1 + std::max(getHeight(curr->left), getHeight(curr->right));
}

TreeNode *AVLTree::rotateLL(TreeNode *curr)
{
    TreeNode *next = curr->left;
    curr->left = next->right;
    next->right = curr;
    calcHeight(curr);
    calcHeight(next);
    return next;
}

TreeNode *AVLTree::rotateLR(TreeNode *curr)
{
    TreeNode *next = curr->left->right;
    curr->left->right = next->left;
    next->left = curr->left;
    curr->left = next->right;
    next->right = curr;
    calcHeight(next->left);
    calcHeight(curr);
    calcHeight(next);
    return next;
}

TreeNode *AVLTree::rotateRL(TreeNode *curr)
{
    TreeNode *next = curr->right->left;
    curr->right->left = next->right;
    next->right = curr->right;
    curr->right = next->left;
    next->left = curr;
    calcHeight(next->right);
    calcHeight(curr);
    calcHeight(next);
    return next;
}

TreeNode *AVLTree::rotateRR(TreeNode *curr)
{
    TreeNode *next = curr->right;
    curr->right = next->left;
    next->left = curr;
    calcHeight(curr);
    calcHeight(next);
    return next;
}

TreeNode *AVLTree::balance(TreeNode *curr)
{
    int balanceFactor = getBalanceFactor(curr);
    if (balanceFactor > 1)
    {
        if (getBalanceFactor(curr->left) == 1)
        {
            return rotateLL(curr);
        }
        return rotateLR(curr);
    }
    if (balanceFactor < -1)
    {
        if (getBalanceFactor(curr->right) == 1)
        {
            return rotateRL(curr);
        }
        return rotateRR(curr);
    }
    return curr;
}

TreeNode *AVLTree::_insert(TreeNode *curr, TreeNode *ptr)
{
    if (!curr)
    {
        return ptr;
    }
    if (ptr->val < curr->val)
    {
        curr->left = _insert(curr->left, ptr);
    }
    else
    {
        curr->right = _insert(curr->right, ptr);
    }
    calcHeight(curr);
    return balance(curr);
}

int AVLTree::predecessor(TreeNode *curr) const
{
    TreeNode *next = curr->left;
    while (next)
    {
        curr = next;
        next = next->right;
    }
    return curr->val;
}

TreeNode *AVLTree::_erase(TreeNode *curr, const int &val)
{
    if (!curr)
    {
        return nullptr;
    }
    if (val == curr->val)
    {
        if (!curr->left && !curr->right)
        {
            delete curr;
            return nullptr;
        }
        if (!curr->left)
        {
            TreeNode *result = curr->right;
            delete curr;
            return result;
        }
        if (!curr->right)
        {
            TreeNode *result = curr->left;
            delete curr;
            return result;
        }
        int nextVal = predecessor(curr);
        curr->val = nextVal;
        curr->left = _erase(curr->left, nextVal);
    }
    else if (val < curr->val)
    {
        curr->left = _erase(curr->left, val);
    }
    else
    {
        curr->right = _erase(curr->right, val);
    }
    calcHeight(curr);
    return balance(curr);
}

void AVLTree::preorder(TreeNode *curr) const
{
    if (curr)
    {
        std::cout << curr->val << " ";
        preorder(curr->left);
        preorder(curr->right);
    }
}

void AVLTree::inorder(TreeNode *curr) const
{
    if (curr)
    {
        inorder(curr->left);
        std::cout << curr->val << " ";
        inorder(curr->right);
    }
}

AVLTree::AVLTree() : root{nullptr} { ; }

void AVLTree::insert(const int &val)
{
    TreeNode *ptr = new TreeNode(val);
    root = _insert(root, ptr);
}

void AVLTree::erase(const int &val)
{
    root = _erase(root, val);
}

void AVLTree::describe() const
{
    std::cout << "Preorder: ";
    preorder(root);
    std::cout << std::endl;
    std::cout << "Inorder: ";
    inorder(root);
    std::cout << std::endl;
}