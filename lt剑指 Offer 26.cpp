// https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
// shu de zi jie gou lcof
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == nullptr || B == nullptr)
            return false;
        return isSame(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool isSame(TreeNode* node1, TreeNode* node2){
        if(node2 == nullptr)
            return true;
        
        if(node1 == nullptr)
            return false;
        if(node1->val == node2->val)
            return isSame(node1->left, node2->left) && isSame(node1->right, node2->right);
        return false;
    }
};