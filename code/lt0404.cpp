#include <iostream>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr), right(nullptr){}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(nullptr, root);
    }

    int helper(TreeNode* parent, TreeNode* next)
    {
        if(next == nullptr)
            return 0;
        
        if(next->left == nullptr  && next->right == nullptr)
        {
            if(parent && parent->left == next)
                return next->val;
            else
                return 0;
        }

        return helper(next, next->left) + helper(next, next->right);

    }
};