#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        int num = 0;
        for(auto node:nodes)
            helper(node, sum, num);
        return num;
    }

    void helper(TreeNode* root, int sum, int& num)
    {
        if(root == nullptr)
            return;

        if(sum == root->val)
            num++;

        helper(root->left, sum - root->val, num);
        helper(root->right, sum - root->val, num);
    }

    void inorder(TreeNode* root, vector<TreeNode*>& res)
    {
        if(root)
        {
            res.push_back(root);
            inorder(root->left, res);
            inorder(root->right, res);
        }
    }
