// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
// er cha sou suo shu de di kda jie dian lcof
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
    int kthLargest(TreeNode* root, int& k) {
        if(root == nullptr)
            return UN_FIND;
        
        int res = kthLargest(root->right, k);
        if(res != UN_FIND)
            return res;
        
        k--;
        if(k == 0){
            return root->val;
        }
        
        res = kthLargest(root->left, k);
        if(res != UN_FIND)
            return res;

        return res;
    }

    const static int UN_FIND = INT_MIN;
};