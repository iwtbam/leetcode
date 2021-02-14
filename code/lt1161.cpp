// https://leetcode-cn.com/problems/maximum-level-sum-of-a-binary-tree/
// maximum level sum of a binary tree
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
    int maxLevelSum(TreeNode* root) {
        if(root == nullptr)
            return -1;
        
        int res = 1, level = 1,  max_sum = INT_MIN;

        queue<TreeNode*> q = {};

        q.push(root);

        while(q.size()){
            int size = q.size();
            int cur_sum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                cur_sum += node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }

            if(cur_sum > max_sum){
                res = level;
                max_sum = cur_sum;
            }

            level++;
        }

        return res;
    }
};