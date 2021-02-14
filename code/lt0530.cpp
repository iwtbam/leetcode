#include <vector>
#include <climits>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> record = {};
        helper(root, record);
        int res = INT_MAX;
        for(int i = 1; i < record.size(); i++){
            res = min(res, record[i] - record[i-1]);
        }
        
        return res;
    }
    
    void helper(TreeNode* root, vector<int>& record){
        if(root)
        {
            helper(root->left, record);
            record.push_back(root->val);
            helper(root->right, record);
        }
    }
};