
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr), right(nullptr){}
};


class Solution{
    TreeNode* upsideDownBinaryTree(TreeNode* root){
        TreeNode* parent = nullptr, *parent_right = nullptr;
        while(root)
        {
            TreeNode* root_left = root->left;
            root->left = parent_right;
            parent_right = root->right;
            root->right = parent;
            parent = root;
            root = root_left;
        }

        return parent;
    }
};