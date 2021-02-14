// https://leetcode-cn.com/problems/clone-n-ary-tree/
// clone n ary tree
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        if(root == nullptr)
            return nullptr;
        
        vector<Node*> children;
        size_t size = root->children.size();
        for(int i = 0; i < size; i++){
            children.push_back(cloneTree(root->children[i]));
        }

        Node* node = new Node(root->val, children);

        return node;
    }
};