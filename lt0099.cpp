struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        helper(root, nullptr);
        swap(first->val, second->val);
        return;
    }

    inline void swap(int& a, int& b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    void helper(TreeNode* root, TreeNode* pre)
    {
        if(root)
        {
            helper(root->left, pre);
            
            if(pre && first == nullptr && pre->val >= root->val)
                first = root;
            
            if(first && pre->val >= root->val)
                second = root;

            pre = root;
            helper(root->right, pre);
        }
    }

private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
};