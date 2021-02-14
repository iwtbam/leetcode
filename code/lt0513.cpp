#include <queue>

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        int res = root->val;
        
        while(nodes.size())
        {
            int size = nodes.size();
            for(int i = 0; i < size; i++)
            {
                auto front = nodes.front();
                
                if(i == 0)
                    res = front->val;
                
                if(front->left)
                    nodes.push(front->left);
                
                if(front->right)
                    nodes.push(front->right);
                
                nodes.pop();
            }
        }
        
        return res;
    }
};