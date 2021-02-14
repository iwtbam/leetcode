#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> postorderTraversal(TreeNode* root) {
        
        if(root == nullptr)
            return {};

        stack<TreeNode*> ns;
        ns.push(root);
        vector<int> iv;
        TreeNode* last = nullptr;
        while(ns.size())
        {
            auto top = ns.top();
            
            if((top->left == nullptr && top->right == nullptr)
               ||(last!=nullptr &&(top->left == last || top->right == last)))
            {
                iv.push_back(top->val);
                last = top;
                ns.pop();
            }
            else
            {
                if(top->right)
                    ns.push(top->right);
                if(top->left)
                    ns.push(top->left);
            }
            
        }
        return iv;
    }
};