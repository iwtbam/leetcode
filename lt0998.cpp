// https://leetcode-cn.com/problems/maximum-binary-tree-ii/
// maximum binary tree ii
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* parent = new TreeNode(INT_MAX);
        parent->left = root;
        helper(root, parent, val, false);
        return parent->left;
    }
    
    void helper(TreeNode* node, TreeNode* parent, int val, bool flag){
        if(flag)
            return;
        
        if(node == nullptr){
            parent->right = new TreeNode(val);
            flag = true;
            return;
        }
        
        if(val < node->val){
            helper(node->right, node, val, flag);
        }else{
            flag = true;
            TreeNode* cur = new TreeNode(val);
            if(parent->left == node){
                parent->left = cur;
                cur->left = node;
            }else{
                parent->right = cur;
                cur->left = node;
            }
          
        }
    }
};