#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define S2

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

#if defined(S1)

//这是一种递归方法很简单

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};

        auto left_res = inorderTraversal(root->left);
        auto right_res = inorderTraversal(root->right);
        left_res.push_back(root->val);
        left_res.insert(left_res.end(), right_res.begin(), right_res.end());
        return left_res;
    }
};

#elif defined(S2)
// 迭代解
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
       stack<TreeNode*> ns;
       vector<int> iv;
       TreeNode* cur = root;
       while(cur !=nullptr || !ns.empty()) 
       {
           if(cur != nullptr)
           {
               ns.push(cur);
               cur = cur->left;
           }
           else
           {
               cur = ns.top();
               ns.pop();
               iv.push_back(cur->val);
               cur = cur->right;
           }
       }
       return iv;
    }

};

#endif

