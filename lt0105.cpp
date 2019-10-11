#include <iostream>
#include <vector>
#include <algorithm>


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

    using IterType = vector<int>::iterator; 

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

    TreeNode* helper(IterType s1, IterType e1, IterType s2, IterType e2){
        if(e1 == s1)
            return nullptr;
        int rval = *s1;
        TreeNode* root = new TreeNode(rval);
        auto iter = find(s2, e2, rval);
        auto dis  = distance(s2, iter);
        root->left  = helper(s1 + 1, s1 + 1 + dis, s2, iter - 1);
        root->right = helper(s1 + 2 + dis, e1, iter + 1, e2);
        return root;
    }
};
