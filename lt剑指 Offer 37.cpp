// https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/
// xu lie hua er cha shu lcof
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "#";
        
        return to_string(root->val) + + " " + serialize(root->left) + " " + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize(ss);
    }

    TreeNode* deserialize(stringstream& ss){
        if(ss.str().size() == 0)
            return nullptr;
        string token;
        ss >> token;
        if(token == "#")
            return nullptr;
        TreeNode* node = new TreeNode(stoi(token));
        node->left = deserialize(ss);
        node->right = deserialize(ss);
        return node;
        
    } 
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));