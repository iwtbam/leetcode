// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
// cong shang dao xia da yin er cha shu ii lcof
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }

        vector<vector<int>> res = {};
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()){
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left != nullptr){
                    q.push(node->left);
                }
                
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            res.push_back(level);
        }

        return res;
    }
};