#include <iostream>
#include <vector>

using namespace std;

// 19-06-02:19-02 没懂这个递归逻辑

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution{
public:
    bool isValidBST(TreeNode* root){
        
        if(root == nullptr)
            return true;

        if(isValidBST(root->left))
        {
            if(cur < root->val)
            {
                cur = root->val;
                return isValidBST(root->right);
            }
        }

        return false;

    }
private:
    int cur = - INT_MAX;
};


int main()
{
    return 0;
}