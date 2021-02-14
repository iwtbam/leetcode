// https://leetcode-cn.com/problems/paths-with-sum-lcci/
// paths with sum lcci
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
    int pathSum(TreeNode* root, int sum) {
        int count = 0;
        inorder(root, sum, count);
        return count ;
    }

    void inorder(TreeNode* root, int sum, int& count){
        if(root == nullptr)
            return;
        inorder(root->left, sum, count);
        helper(root, 0, sum, count);
        inorder(root->right, sum, count);
    }

    void helper(TreeNode* root, int cur, int sum, int& count){
        if(root == nullptr)
            return;
        cur = cur + root->val;
        if(cur == sum){
            count++;
        }

        helper(root->left, cur, sum, count);
        helper(root->right, cur , sum, count);
        return ;
    }
};