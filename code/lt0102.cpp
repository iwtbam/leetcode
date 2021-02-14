#include <iostream>
#include <queue>
#include <vector>


using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<vector<int>> res = {};
        
        nodes.push(root);
        
        while(nodes.size())
        {
            int size = nodes.size();
            vector<int> iv = {};
            for(int i = 0; i < size ; i++)
            {
                auto front = nodes.front();
                nodes.pop();
                iv.push_back(front->val);
            
                if(front->left)
                    nodes.push(front->left);
                if(front->right)
                    nodes.push(front->right);
            }

            res.push_back(iv);
        }
        return res;
    }
};