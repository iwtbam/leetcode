#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//2019-06-03:11-12 递归高度我感觉很垃圾, 虽然能过, 应该有特别优的策略

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr), right(nullptr){}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {

        if(root == nullptr)
            return true;
        
        return abs(height(root->left) - height(root->right)) < 2 &&
                isBalanced(root->left) && isBalanced(root->right);      
    }

    int height(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};


int main()
{
    return 0;
}