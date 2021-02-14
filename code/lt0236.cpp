#include <vector>

using namespace std;

#define S1

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

#if defined (S2)

//2019-06-19:20-32

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)
            return nullptr;
        
        if(p == q)
            return p;
        
        TreeNode* res = root;
        
        if(helper(root->left, p) && helper(root->left, q))
            res = lowestCommonAncestor(root->left, p, q);
        
      
        if(res==root && helper(root->right, p) && helper(root->right, q))
           
            res = lowestCommonAncestor(root->right, p, q);
        return res;

        
    }
    
    bool helper(TreeNode* root, TreeNode* node)
    {
        
        if(root == node)
            return true;
        
        if(root == nullptr)
            return false;
        bool res = false;
        bool isleft  = helper(root->left,  node);
        bool isright = helper(root->right, node);
        
        res = isleft || isright;
        return res;
    }
};


#else
// 看一下解法
class Solution{
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == p || root == q)
            return root;
        
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);

        if(!left && !right)
            return nullptr;
        else if(left && !right)
            return left;
        else if(right && !left)
            return right;
        
        return root;
    }
};

#endif