#include <string>
#include <sstream>
using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){};
};

class Codec {
public:

    string serialize(TreeNode* root) {
       stringstream ss;
       serialize(root, ss);
       return ss.str();
    }

    void serialize(TreeNode* root, stringstream& ss)
    {
        if(root == nullptr)
        {
            ss << "# ";
            return;
        }
        ss << root->val << " ";
        serialize(root->left, ss);
        serialize(root->right, ss);
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize(ss);
    }

    TreeNode* deserialize(stringstream& ss)
    {
        string val;
        ss >> val;
        if(val == "#")
            return nullptr;
      
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(ss);
        root->right = deserialize(ss);
        return root;
    }
};