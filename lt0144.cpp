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

class Solution{
public:
    vector<int> preorderTraversal(TreeNode* root){
        stack<TreeNode*> ns;
        vector<int> ni;

        ns.push(root);
        while(ns.size())
        {
            auto top = ns.top();
            ni.push_back(top->val);
            ns.pop();
            if(top->right)
                ns.push(top->right);
            
            if(top->left)
                ns.push(top->left);

        }
        return ni;
    }
};

int main()
{

}