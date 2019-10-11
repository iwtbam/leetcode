#include <cmath>

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
    int closestValue(TreeNode* root, double target) {
        TreeNode* cur = root, *pre = nullptr;
        int record = cur->val;
        while(cur)
        {
            if(pre && fabs(cur->val - target) < fabs(record - target))
                record = cur->val;
            pre = cur;            
            if(target > cur->val)
                cur = cur->right;
            else if(target < cur->val)
                cur = cur->left;
            else
                return cur->val;            
        }
        return record;
    }
};