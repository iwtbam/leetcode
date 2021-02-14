// https://leetcode-cn.com/problems/maximum-product-of-splitted-binary-tree/
// maximum product of splitted binary tree
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
    int maxProduct(TreeNode* root) {
        vector<long long> cache = {};
        helper(root, cache);

        long long max_val = 0;

        long long total = helper(root, cache);

        for(auto val : cache){
            max_val = max(max_val, (total - val) * val);
        }
        return max_val % MOD;
    }

    long long helper(TreeNode* node, vector<long long>& cache){
        if(node == nullptr)
            return 0;

        long long left = helper(node->left, cache);
        long long right = helper(node->right, cache);
        cache.push_back(left + right + node->val);
        return left + right + node->val;
    }

    static const long long MOD = pow(10, 9) + 7;
};