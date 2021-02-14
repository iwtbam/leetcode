// https://leetcode-cn.com/problems/delete-nodes-and-return-forest/
// delete nodes and return forest
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res = {};
        unordered_set<int> del_sets = {to_delete.begin(), to_delete.end()};
        dfs(root, res, del_sets, 1);
        return res;
    }

    void dfs(TreeNode*& node, vector<TreeNode*>& roots, unordered_set<int>& to_delete, int parent_delete_flag){
        if(node == nullptr)
            return;
        int node_delete_falg = to_delete.count(node->val);
        dfs(node->left,  roots, to_delete, node_delete_falg);
        dfs(node->right, roots, to_delete, node_delete_falg);
        if(parent_delete_flag && !node_delete_falg)
            roots.push_back(node);
        if(node_delete_falg)
            node = nullptr;
    }
};