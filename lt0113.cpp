#include <iostream>
#include <vector>


using namespace std;

//2019-06-05:15-33 S1 能 A 效果很差

#define S1

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr), right(nullptr){}
};

#if defined(S1)

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
       vector<vector<int>> paths = {};
       pathSumHelper(root, sum ,paths, {});
       return paths;
    }

    void pathSumHelper(TreeNode* root, int sum, vector<vector<int>>& paths, vector<int> path){
        if(root == nullptr)
            return;
        
        int res = sum - root->val;

        path.push_back(root->val);
       
        pathSumHelper(root->left, res, paths, path);
        pathSumHelper(root->right, res, paths, path);
        
        if(root->left == nullptr && root->right == nullptr && res == 0)
            paths.push_back(path);

        path.pop_back();
    }
};

#elif defined(S2)

#endif