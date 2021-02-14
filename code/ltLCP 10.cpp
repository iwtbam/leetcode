// https://leetcode-cn.com/problems/er-cha-shu-ren-wu-diao-du/
// er cha shu ren wu diao du
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
    double minimalExecTime(TreeNode* root) {
        auto res = dfs(root);
        return res.second;
    }

    pair<int, double> dfs(TreeNode* node){
        if(node == nullptr)
            return {0, 0.0};
        
        auto l  = dfs(node->left);
        auto r = dfs(node->right);
        return {l.first + r.first + node->val, node->val + max(max(l.second, r.second), (l.first + r.first) / 2.0)};
    }
};