#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};


class Solution{
public:
    
    void flatten(TreeNode* root){
       if(root == nullptr)
            return;

        if(pre == nullptr)
            pre = root;
        else
        {
            pre->left = nullptr;
            pre->right = root;
            pre = root;
        }

        auto left = root->left;
        auto right = root->right;
    
        flatten(left);
        flatten(right);
    }

private:

    TreeNode* pre = nullptr;

};