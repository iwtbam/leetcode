

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        int cur = 0;
        return helper(root, p, cur);
    }
    
    TreeNode* helper(TreeNode* root, TreeNode* p, int& cur)
    {
        if(root == nullptr)
            return nullptr;
        
        TreeNode* res = nullptr;
        res = helper(root->left, p, cur);
        res = res ? res : (cur ?  root : res); 
        cur = root == p ? 1 : 0;
        res = res ? res : helper(root->right, p, cur);
        return res;
    }
}