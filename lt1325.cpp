// https://leetcode-cn.com/problems/delete-leaves-with-a-given-value/
// delete leaves with a given value
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode head = {0};
        head.left = root;
        helper(root, &head, target);
        return head.left;
    }
    
    TreeNode* helper(TreeNode* node, TreeNode* parent, int target){
        
        if(node == nullptr)
            return nullptr;
        
        TreeNode* left = helper(node->left, node, target);
        TreeNode* right = helper(node->right, node, target);
        
        if(left == nullptr && right == nullptr && node->val == target){
            if(parent->left == node)
                parent->left = nullptr;
            else
                parent->right = nullptr;
            node = nullptr;
        }
        
        return node;
    }
};