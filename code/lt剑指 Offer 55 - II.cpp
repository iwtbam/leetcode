// https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/
// ping heng er cha shu lcof
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        
        int lh = height(root->left);
        int rh = height(root->right);
        if(abs(lh - rh) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode* node){
        if(node == nullptr)
            return 0;
        
        if(memos.count(node))
            return memos[node];
        memos[node] =  max(height(node->left), height(node->right)) + 1;
        return memos[node];
    }

private:
    unordered_map<TreeNode*, int> memos = {};
};