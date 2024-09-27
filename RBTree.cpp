#include "RBTree.h"

RBTree::RBTree() : root{nullptr} { ; }

TreeNode *RBTree::rotateLL(TreeNode *curr)
{
    TreeNode *next = curr->left;
    curr->left = next->right;
    next->right = curr;
    next->isRed = false;
    curr->isRed = true;
    return next;
}

TreeNode *RBTree::rotateLR(TreeNode *curr)
{
    TreeNode *next = curr->left->right;
    curr->left->right = next->left;
    next->left = curr->left;
    curr->left = next->right;
    next->right = curr;
    next->isRed = false;
    curr->isRed = true;
    return next;
}

TreeNode *RBTree::rotateRL(TreeNode *curr)
{
    TreeNode *next = curr->right->left;
    curr->right->left = next->right;
    next->right = curr->right;
    curr->right = next->left;
    next->left = curr;
    next->isRed = false;
    curr->isRed = true;
    return next;
}

TreeNode *RBTree::rotateRR(TreeNode *curr)
{
    TreeNode *next = curr->right;
    curr->right = next->left;
    next->left = curr;
    next->isRed = false;
    curr->isRed = true;
    return next;
}

TreeNode *RBTree::_insert(TreeNode *curr, TreeNode *ptr)
{
    if (!curr)
    {
        return ptr;
    }
    if (ptr->val < curr->val)
    {
        if (!curr->left || !curr->left->isRed)
        {
            curr->left = _insert(curr->left, ptr);
            return curr;
        }
        if (ptr->val < curr->left->val)
        {
            curr->left->left = ptr;
        }
        else
        {
            curr->left->right = ptr;
        }
        if (curr->right && curr->right->isRed)
        {
            curr->left->isRed = false;
            curr->right->isRed = false;
            curr->isRed = true;
            return curr;
        }
        if (curr->left->left == ptr)
        {
            return rotateLL(curr);
        }
        return rotateLR(curr);
    }
    if (!curr->right || !curr->right->isRed)
    {
        curr->right = _insert(curr->right, ptr);
        return curr;
    }
    if (ptr->val < curr->right->val)
    {
        curr->right->left = ptr;
    }
    else
    {
        curr->right->right = ptr;
    }
    if (curr->left && curr->left->isRed)
    {
        curr->left->isRed = false;
        curr->right->isRed = false;
        curr->isRed = true;
        return curr;
    }
    if (curr->right->left == ptr)
    {
        return rotateRL(curr);
    }
    return rotateRR(curr);
}

int RBTree::predecessor(TreeNode *curr) const
{
    TreeNode *next = curr->left;
    while (next)
    {
        curr = next;
        next = next->right;
    }
    return curr->val;
}

// TreeNode *RBTree::_erase(TreeNode *curr, const int &val)
// {
//     if (!curr)
//     {
//         return nullptr;
//     }
//     if (val == curr->val)
//     {
//         if (!curr->left && !curr->right)
//         {
//             delete curr;
//             return nullptr;
//         }
//         if (!curr->left)
//         {
//             TreeNode *result = curr->right;
//             delete curr;
//             return result;
//         }
//         if (!curr->right)
//         {
//             TreeNode *result = curr->left;
//             delete curr;
//             return result;
//         }
//         int nextVal = predecessor(curr);
//         curr->val = nextVal;
//         curr->left = _erase(curr->left, nextVal);
//         return curr;
//     }
// }

void RBTree::preorder(TreeNode *curr) const
{
    if (curr)
    {
        std::cout << curr->val << "(" << curr->isRed << ") ";
        preorder(curr->left);
        preorder(curr->right);
    }
}

void RBTree::inorder(TreeNode *curr) const
{
    if (curr)
    {
        inorder(curr->left);
        std::cout << curr->val << "(" << curr->isRed << ") ";
        inorder(curr->right);
    }
}

void RBTree::insert(const int &val)
{
    TreeNode *ptr = new TreeNode(val);
    root = _insert(root, ptr);
    root->isRed = false;
}

// void RBTree::erase(const int &val)
// {
//     root = _erase(root, val);
// }

void RBTree::describe() const
{
    std::cout << "Preorder: ";
    preorder(root);
    std::cout << std::endl;
    std::cout << "Inorder: ";
    inorder(root);
    std::cout << std::endl;
}