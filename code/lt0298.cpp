#include <algorithm>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    int longestConsecutive(TreeNode* root){
        if(root == nullptr)
            return 0;
        int max_length = INT_MIN;
        helper(nullptr, root, 1, max_length);
    }

    void helper(TreeNode* pre, TreeNode* root, int length, int& max_length){
        
        max_length = max(length, max_length);
        
        if(root == nullptr)
            return;

        if(pre)
        {
            if(root->val == pre->val + 1)
                length++;
            else
                length = 1;
        }

        helper(root, root->left,  length, max_length);
        helper(root, root->right, length, max_length);
    }
};