#include <algorithm>


using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution{
public:
    int countUnivalSubtrees(TreeNode* root){
        bool res = true;
        return countUnivalSubtrees(root, res);
    }

    int countUnivalSubtrees(TreeNode* root, bool& res){
        
        if(root == nullptr){
            res = true;
            return 0;
        }
        
        if(root->left == nullptr  &&  root->right == nullptr){
            res = true;
            return 1;
        }
        
        int ans = 0;

        bool r1, r2;

        ans += countUnivalSubtrees(root->left, r1);
        ans += countUnivalSubtrees(root->right, r2);

        res = r1 && r2;

        if(res && root->left && root->val != root->left->val)
            res = false;
        
        if(res && root->right && root->val != root->right->val)
            res = false;
        
        if(res)
            ans++;
        return ans;
    }
};