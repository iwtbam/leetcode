#include <vector>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        helper(root, res, "");
        return res;
    }
    
    void helper(TreeNode* root, vector<string>& res, string s)
    {
        if(root == nullptr)
            return;
        
        if(root->left==nullptr&& root->right==nullptr)
        {
            s += to_string(root->val);
            res.push_back(s);
            return;
        }
        
        s += to_string(root->val);
        s += "->";
        helper(root->left, res, s);
        helper(root->right, res, s);
    }
};