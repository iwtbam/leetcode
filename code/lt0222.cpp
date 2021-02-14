#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        
        if(root->left == nullptr && root->right == nullptr)
            return 1;

        return countNodes(root->left) + countNodes(root->right);
    }
};