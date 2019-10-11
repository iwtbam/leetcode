struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        if(s == nullptr && t == nullptr)
            return true;
        if(s == nullptr || t == nullptr)
            return false;
        
        return isEqual(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);    
    }
    
    bool isEqual(TreeNode* s, TreeNode* t){
        if(s == nullptr && t == nullptr)
            return true;
        if(s == nullptr || t == nullptr)
            return false;
        
        return s->val == t->val && isEqual(s->left, t->left) && isEqual(s->right, t->right);
    }
};