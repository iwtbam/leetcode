#include <iostream>
#include <vector>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr), right(nullptr){}
};

class Solution{
public:
    bool hasPathSum(TreeNode* root, int sum){
        if(root == nullptr)
            return false;

        int res = sum - root->val;

        if(res == 0 && root->left == nullptr && root->right == nullptr)
            return true;

        return hasPathSum(root->left, res) || hasPathSum(root->right, res);

    }
};