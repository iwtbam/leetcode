// https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
// zhong jian er cha shu lcof
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder  = inorder;
        return buildTree(0, preorder.size(), 0, inorder.size());
    }

    TreeNode* buildTree(int l1, int r1, int l2, int r2){
        if(r1 - l1 == 1)
            return new TreeNode(preorder[l1]);
        if(r1 - l1 == 0)
            return nullptr;
        
        TreeNode* node = new TreeNode(preorder[l1]);
        int pos = find(inorder.begin() + l2, inorder.begin() + r2, preorder[l1]) - inorder.begin();
        int dis = pos - l2;
        node->left  = buildTree(l1 + 1, l1 + dis + 1, l2, pos);
        node->right = buildTree(l1 + dis + 1, r1, pos + 1, r2);
        return node;
    }
    
private:
    vector<int> preorder;
    vector<int> inorder;
};