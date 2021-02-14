// https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
// er cha shu zhong he wei mou yi zhi de lu jing lcof
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path = {};
        return pathSum(root, sum, path);
    }

    vector<vector<int>> pathSum(TreeNode* node, int sum, vector<int>& path){
        if(node == nullptr)
            return {};

        if(node->left == nullptr && node->right == nullptr){
            if(sum == node->val){
                vector<int> temp = path;
                temp.push_back(node->val);
                return {temp};
            }
        }

        vector<vector<int>> res = {};
        path.push_back(node->val);
        auto left = pathSum(node->left, sum - node->val, path);
        auto right = pathSum(node->right, sum - node->val, path);
        path.pop_back();
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        return move(res);
    }
};