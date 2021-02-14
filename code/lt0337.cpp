#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

#if defined S1
//2019-07-23: 超时, 解法没问题
class Solution {
public:
    int rob(TreeNode* root) {
        return rob(root, false) ;
    }

    int rob(TreeNode* root, bool last_rob)
    {
        if(root == nullptr)
            return 0;
        
        int both_not_rob = rob(root->left,  false) + rob(root->right,  false);
        if(last_rob)
            return rob(root->left,  false) + rob(root->right,  false);
        else
            return max(root->val + rob(root->left,  true) + rob(root->right,  true), both_not_rob) ; 

    }
};

#else

#endif