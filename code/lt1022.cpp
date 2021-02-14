// https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers/
// sum of root to leaf binary numbers
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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        helper(root, 0, sum);
        return sum;
    }
    
    void helper(TreeNode* node, int prefix, int& sum){
        if(node == nullptr)
                return;
        
        int cur = prefix * 2 + node->val;
        
        if(node->left == nullptr && node->right == nullptr){
            sum += cur;
            return;
        }
        
        helper(node->left,  cur, sum);
        helper(node->right, cur, sum);
    }
    
};