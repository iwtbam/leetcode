#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//2019-06-02:22-47 水题, 越水越开心

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr), right(nullptr){}
};

class Solution{
public:
    int maxDepth(TreeNode* root){
        if(root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;        
    }
};