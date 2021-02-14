// https://leetcode-cn.com/problems/deepest-leaves-sum/
// deepest leaves sum
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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q = {};
        q.push(root);
        int res = 0;
        while(q.size()){
            int size = q.size();
            int sum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                sum += node->val;
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
            }
            
            res = sum;
        }
        
        return res;
    }
};