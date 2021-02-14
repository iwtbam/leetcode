#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr), right(nullptr){}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        long sum = 0;
        helper(root, "", sum);
        return sum;
    }
    
    void helper(TreeNode* root, string s, long& sum){
        if(root == nullptr)
            return;
        
        if(root->left == nullptr && root->right == nullptr)
        {
            s += to_string(root->val);
            sum += stol(s);
            return;
        }
        
        s += to_string(root->val);
        helper(root->left, s, sum);
        helper(root->right, s, sum);
        
    }
};