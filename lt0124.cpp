#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr), right(nullptr){}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
          max_gain(root);
          return max_sum;
    }

    int max_gain(TreeNode* root){
        if(root == nullptr)
            return 0;

        int left_gain  = max(max_gain(root->left), 0);
        int right_gain = max(max_gain(root->right), 0);

        int price_new_path = root->val + left_gain + right_gain;

        max_sum = max(max_sum, price_new_path);

        return root->val + max(left_gain, right_gain);
    }

private:
    int max_sum = INT_MAX;
};