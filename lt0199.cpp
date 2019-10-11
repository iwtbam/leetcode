#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    vector<int> rightSideView(TreeNode* root){
        
        if(root == nullptr)
            return {};

        queue<TreeNode*> nq;
        vector<int> iv;

        nq.push(root);
        
        while(nq.size())
        {
            int len = nq.size();
            for(int i = 0; i < len; i++)
            {
                auto front = nq.front();
                nq.pop();
                if(i == len - 1)
                    iv.push_back(front->val);
                
                if(front->left)
                    nq.push(front->left);
                
                if(front->right)
                    nq.push(front->right);
            }
        }

        return iv;
    }
};