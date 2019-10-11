#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};


class Solution
{
public:
    vector<TreeNode*> generateTrees(int n){
        if(n == 1)
            return { nullptr };
        return generate_trees_helpers(0, n - 1);
    }
    vector<TreeNode*> generate_trees_helpers(int start, int end)
    {
        vector<TreeNode*> res = {};
        if(start > end)
        {
            res.push_back(nullptr);
            return res;
        }

        for(int i = start; i <= end; i++)
        {
            auto left_res = generate_trees_helpers(start, i - 1);
            auto right_res = generate_trees_helpers(i + 1, end);

            for(auto l : left_res)
            {
                for(auto r : right_res)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }

        return res;
    }      
};