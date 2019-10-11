#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int target = 0;
        kthSmallest(root, k, target);
        return target;
    }
    
    bool kthSmallest(TreeNode* root, int k, int& target){
        
        if(root)
        {
            if(kthSmallest(root->left, k, target))
                return true;
            
            if(--k == 0){
                target = root->val;
                return true;
            }
            
            if(kthSmallest(root->right, k, target))
                return true;
        }
        
        return false;
    }
};