struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == nullptr)
            return nullptr;
        
        TreeNode* target = root;
        TreeNode* pre = nullptr;
        while(target && target->val != key)
        {
            pre = target;
            if(target->val > key)
                target = target->left;
            else
                target = target->right;
        }
        
       
        
        if(target == nullptr)
            return root;
        
        TreeNode* node = target;
            
        if(node->left)
        {
            pre = node;
            node = node->left;
            while(node->right){
                pre = node;
                node = node->right;
            }
        }
        else
        {
            if(node->right)
            {
                pre = node;
                node = node->right;
                while(node->left){
                    pre = node;
                    node = node->left;
                }
            }
        }
        
        target->val = node->val;
        
        if(pre == nullptr)
            return nullptr;
        
        TreeNode* next = node->left ? node->left : node->right;
        
        if(pre->left == node)
            pre->left = next;
        else
            pre->right = next;
        
        return root;
    }
};