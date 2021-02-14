// https://leetcode-cn.com/problems/number-of-good-leaf-nodes-pairs/
// number of good leaf nodes pairs
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        if(distance <= 1)
            return 0;
        int ans = 0;
        countPairs(root, distance, ans);
        return ans;
    }
    
    vector<int> countPairs(TreeNode* root, int distance, int& ans){

        vector<int> res(distance, 0);

        if(root == nullptr)
            return res;
        
        if(root->left == nullptr && root->right == nullptr){
           res[1] = 1;
           return res;
        }
        
        
        vector<int> left = countPairs(root->left, distance, ans); 
        vector<int> right = countPairs(root->right, distance, ans);
        
        vector<int> sum(distance, 0);
        
     
        
        
        for(int i = 1; i < distance; i++){
            sum[i] = sum[i - 1] + right[i];
        }
  
        
        for(int i = 1; i < distance; i++){
            ans = ans + left[i] * sum[distance - i];
        }
        
        for(int i = distance - 1; i >= 1; i--){
            left[i] = left[i - 1] + right[i - 1];
        }
        left[1] = 0;
        return left;
    }
};