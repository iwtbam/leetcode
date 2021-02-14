#include <iostream>
#include <deque>
#include <vector>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res = {};
        queue<TreeNode*> nodes;
        int dir = 0;
        while(nodes.size())
        {
            int size = nodes.size();
            vector<int> iv;
            for(int i = 0; i < size; i++)
            {
                auto front = nodes.front();
                nodes.pop();
                iv.push_back(front->val);
                if(front->left)
                    nodes.push(front->left);

                if(front->right)
                    nodes.push(front->right);
                
            }
            
            dir ? res.emplace_back(iv.rbegin(), iv.rend()) : res.emplace_back(iv.begin(), iv.end());
            dir = dir ? 0 : 1;
        }

        return res;
    }
};

int main()
{
    deque<TreeNode*> nodes;
    TreeNode* root = new TreeNode(1);
    // nodes.insert()
    nodes.push_front(root);
    auto front = nodes.front();
    nodes.pop_front();

    if(front == nullptr)
        cout << "false" << endl;
    else
    {
        cout << front->val << endl;
    }
    return 0;
    
}