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

class Solution{
public:

    using IterType = vector<int>::iterator;

    TreeNode* buildTree(vector<int> & inorder, vector<int>& postorder){
        return nullptr;
    }

    TreeNode* buildTree(IterType& s1, IterType& e1, IterType& s2, IterType& e2){
        if(e1 <= s1)
            return nullptr;
        
        int rval = *(e2 - 1);
        
        TreeNode* root = new TreeNode(rval);

        auto iter = find(s1, e1, rval);
        auto dis = distance(s1, iter);

        root->left = buildTree(s1, iter, s2, s2 + dis);
        root->right = buildTree(iter + 1, e1, s2 + dis, e2 - 1);
        return root;
    }
};