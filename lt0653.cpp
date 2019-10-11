#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> data;
        inorder(root, data);
        int i = 0, j = data.size() -1;

        while(i < j)
        {
            if(data[i] + data[j] == k)
                return true;
            
            if(data[i] + data[j] < k)
                i++;
            else
                j--;
        }

        return false;
    }

    void inorder(TreeNode* root, vector<int>& data)
    {
        if(root)
        {
            inorder(root->left,data);
            data.push_back(root->val);
            inorder(root->right,data);
        }
    }
};