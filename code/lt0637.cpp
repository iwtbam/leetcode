#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr), right(nullptr){};
};


class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr)
            return {};

        queue<TreeNode*> q;
        vector<double> res ={};
        q.push(root);
        int level_size = 1;
        while(q.size())
        {
            double ans = 0;
            int level_size = q.size();
            for(int i = 0; i < level_size; i++)
            {
                auto front = q.front(); 
                ans += front->val;
                if(front->left)
                    q.push(front->left);
                if(front->right)
                    q.push(front->right);      
            }

            res.push_back(ans/level_size);
        }

        return res;      
    }
};