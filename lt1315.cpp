// https://leetcode-cn.com/problems/sum-of-nodes-with-even-valued-grandparent/
// sum of nodes with even valued grandparent
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
    int sumEvenGrandparent(TreeNode* root) {
        helper(root, 1, 1);
        return sum;
    }
    
    void helper(TreeNode* node, int parent, int grandpa){
        if(node == nullptr)
            return;
        
        if(grandpa % 2 == 0)
            sum += node->val;
        
        helper(node->left, node->val, parent);
        helper(node->right, node->val, parent);
       
    }
    
    int sum = 0;
};