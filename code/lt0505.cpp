#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x):val(x),left(nullptr), right(nullptr){};
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        int cs = 1;
        while(q.size())
        {
            int maxv = INT_MIN;
            for(int  i = 0; i < cs; i++)
            {
                auto front = q.front();
                maxv = max(maxv, front->val);
                if(front->left)
                    q.push(front->left);

                if(front->right)
                    q.push(front->right);

                q.pop(); 
            }
            res.push_back(maxv);
            cs = q.size();
        }

        return res;
    }
};