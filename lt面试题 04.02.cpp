// https://leetcode-cn.com/problems/minimum-height-tree-lcci/
// minimum height tree lcci
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r){
        if(l == r)
            return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums, l, mid);
        node->right = sortedArrayToBST(nums, mid + 1, r);
        return node;
    }
};