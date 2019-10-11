#include <unordered_map>
#include <utility>
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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == nullptr)
            return false;
        
        unordered_map<int, pair<int, TreeNode*>> record;
        helper(root, nullptr,  0,  record);
        auto p1 = record[x];
        auto p2 = record[y];
        return p1.first == p2.first && p1.second != p2.second;
        
    }
    
    void helper(TreeNode* root, TreeNode* pre,int depth,  unordered_map<int, pair<int, TreeNode*>>& record){
        if(root){
            record[root->val] = {depth, pre};
            helper(root->left, root, depth + 1, record);
            helper(root->right, root, depth + 1, record);
        }
    }
};