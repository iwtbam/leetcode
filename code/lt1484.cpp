// https://leetcode-cn.com/problems/clone-binary-tree-with-random-pointer/
// clone binary tree with random pointer
/**
 * Definition for a binary tree node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */
class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        NodeCopy* copy = clone(root);
        cloneRandom(copy, root);
        return copy;
    }

    NodeCopy* clone(Node* root){
        if(root == nullptr)
            return nullptr;
        
        NodeCopy* copy = new NodeCopy(root->val);
        copy->left =  clone(root->left);
        copy->right = clone(root->right);
        relations[root] = copy;
        return copy;
    }

    void cloneRandom(NodeCopy* copy, Node*  node){
        if(node == nullptr)
            return;
        copy->random = relations[node->random];
        cloneRandom(copy->left, node->left);
        cloneRandom(copy->right, node->right);
    }

private:
    unordered_map<Node*, NodeCopy*> relations;
};