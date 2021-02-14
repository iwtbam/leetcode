#include <vector>

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
    vector<int> findMode(TreeNode* root) {
        
        vector<int> res;
        if(root == nullptr)
            return res;
        int cur_times = 1, max_times = 0;
        TreeNode* pre = nullptr;
        inorder(root, pre, cur_times, max_times, res);
        return res;
    }

    void inorder(TreeNode* root, TreeNode* &pre, int& cur_times, int& max_times, vector<int>& res)
    {
        if(root == nullptr)
            return;
        
        inorder(root->left, pre, cur_times, max_times, res);
        if(pre)
            cur_times = (root->val == pre->val) ? cur_times + 1:1;

        if(cur_times == max_times)
            res.push_back(root->val);
        else if(cur_times > max_times)
        {
            res.clear();
            res.push_back(root->val);
            max_times = cur_times;
        }

        pre = root;

        inorder(root->right, pre, cur_times, max_times, res);        

    }
};