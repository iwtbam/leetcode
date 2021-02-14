// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
// er cha sou suo shu yu shuang xiang lian biao lcof
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* pre = nullptr, *head = nullptr;
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr)
            return nullptr;
        
        inorder(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

    void inorder(Node* node){
        if(node == nullptr)
            return;
        
        inorder(node->left);

        if(pre != nullptr){
            pre->right = node;
            node->left = pre;
        }else{
            head = node;
        }

        //cout << node->val << endl;
        pre = node;
        inorder(node->right);
    }
};