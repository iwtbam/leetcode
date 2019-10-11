#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while(root){
            _con.push(root);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* node = _con.top();
        _con.pop();
        int val = node->val;
        node = node->right;
        while(node){
            _con.push(node);
            node = node->left;
        }
        
        return val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return _con.size();
    }

private:
    stack<TreeNode*> _con;
};
