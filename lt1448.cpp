// https://leetcode-cn.com/problems/count-good-nodes-in-binary-tree/
// count good nodes in binary tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return goodNodes(root, INT_MIN);
    }
    
    int goodNodes(TreeNode* root, int max_val){
        if(root == nullptr)
            return 0;
        int res = 0;
        if(root->val >= max_val){
            res = 1;
            max_val = root->val;
        }
        
        res += goodNodes(root->left, max_val);
        res += goodNodes(root->right, max_val);
        return res;
    }
};