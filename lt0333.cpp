#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr), right(nullptr){}
};


class Solution{
public:
    int largetBSTSubtree(TreeNode* root){
        bool res = true;
        int mval = INT_MIN;
        return largestBSTSubtree(root, res, mval);
    }


    int largestBSTSubtree(TreeNode* root, bool& res, int& mval){
        if(root == nullptr){
            res = true;
            return 0;
        }

        mval = max(root->val, mval);

        if(root->left == nullptr && root->right == nullptr){
            res = true;
            return 1;
        }

        int left_nodes = 0, right_nodes = 0, lmvl = INT_MIN, rmvl = INT_MIN;

        left_nodes = largestBSTSubtree(root->left, res, lmvl);

        if(res)
            right_nodes = largestBSTSubtree(root->right, res, rmvl);


        if(res && root->left && (root->val < root->left->val || root->val < lmvl))
            res = false;
        
        if(res && root->right && (root->val > root->right->val || root->val > rmvl))
            res = false;

        if(res)
            left_nodes = left_nodes + right_nodes + 1;

        return max(left_nodes, right_nodes);        
    }
};