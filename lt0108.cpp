#include <iostream>
#include <vector>

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

    using IterType = vector<int>::iterator;

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        if(nums.empty())
            return nullptr;

        int size = nums.size();
        int mid = size / 2;

        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> left_tree = {nums.begin(), nums.begin() + mid};
        vector<int> right_tree = {nums.begin() + mid + 1, nums.end()};
        root->left = sortedArrayToBST(left_tree);
        root->right = sortedArrayToBST(right_tree);
        return root;
    }
};

int main()
{

}