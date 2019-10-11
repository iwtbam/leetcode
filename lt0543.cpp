#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        height(root);
        return max_len;
        
    }

    
    int height(TreeNode* root)
    {        
        if(root == nullptr)
            return  0;   
        int lh = height(root->left); 
        int rh = height(root->right);
        max_len = max(max_len, lh + rh);
        return 1 + max(lh, rh);
    }
    
private:
    int max_len = INT_MIN;
};