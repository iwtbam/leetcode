#include <vector>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution
{
public:
    string tree2str(TreeNode* t){

        if(t == nullptr)
            return {};

        if(t->left == nullptr && t->right == nullptr)
            return to_string(t->val);

        string left = tree2str(t->left);
        string right = tree2str(t->right);
        
        if(left.size())
            left = "(" + left + ")";
        
        if(right.size()){
            right = "(" + right + ")";
            if(left.empty())
                left = "(" + left + ")";
        }
                   
        return to_string(t->val) + left + right; 
    }
};