// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
// cong shang dao xia da yin er cha shu iii lcof
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
        if(root == nullptr)
            return {};
        vector<vector<int>> res = {};
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(q.size()){
            size_t size = q.size();
            vector<int> rows = {};
            
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                rows.push_back(node->val);
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            
            if(level % 2 == 1){
                reverse(rows.begin(), rows.end());
            }
            level = level + 1;
            res.emplace_back(move(rows));
        }
        return res;
    }
};