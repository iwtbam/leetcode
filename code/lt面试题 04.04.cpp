// https://leetcode-cn.com/problems/check-balance-lcci/
// check balance lcci
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
        height(root);
        return res;
    }

    int height(TreeNode* node){
        if(node == nullptr)
            return 0;
        
        int left = height(node->left);
        int right = height(node->right);
        
        res = res && abs(left - right) <= 1;

        return max(left, right) + 1;
    }

private:
    bool res = true;
};