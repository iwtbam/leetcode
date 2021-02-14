// https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees/
// all elements in two binary search trees
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ele1 = {};
        vector<int> ele2 = {};
        inorder(root1, ele1);
        inorder(root2, ele2);
        return merge(ele1, ele2);
    }

    void inorder(TreeNode* node, vector<int>& eles){
        if(node == nullptr)
            return;
        inorder(node->left, eles);
        eles.push_back(node->val);
        inorder(node->right, eles);
    }

    vector<int> merge(const vector<int>& ele1, const vector<int>& ele2){
        int p1 = 0, p2 = 0, p = 0, s1 = ele1.size(), s2 = ele2.size();
        vector<int> res(s1 + s2, 0);
        while(p1 < s1 || p2 < s2){
            int e1 = p1 < s1 ? ele1[p1] : INT_MAX;
            int e2 = p2 < s2 ? ele2[p2] : INT_MAX;
            if(e1 < e2){
                res[p++] = ele1[p1++];
            }else{
                res[p++] = ele2[p2++];
            }
        }
        return res;
    }
};