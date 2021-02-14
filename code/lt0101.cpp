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
//2019-06-02:19-35 递归解法简单 可以试试迭代
class Solution {
public:
    bool isSymmetrix(TreeNode* node){
        if (node == nullptr)
            return true;

        return helper(node->left, node->right);
    }

    bool helper(TreeNode* node1, TreeNode* node2){
        if(node1 == nullptr && node2 == nullptr)
            return true;
        
        if(node1 != nullptr && node2 != nullptr)
        {
            if(node1->val == node2->val)
                return helper(node1->left, node2->right) && helper(node1->right, node2->left);
        }

        return false;
    }
}