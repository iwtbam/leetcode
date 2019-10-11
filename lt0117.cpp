#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};


#if defined (S1)

//2019-06-17:16-18 很耗时

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==nullptr)
            return nullptr;
        
        queue<Node*> q;
        q.push(root);
        while(q.size())
        {
            int len = q.size();
            for(int i = 0; i < len ; i++)
            {
                Node* pre = q.front();
                q.pop();
                
                if(i!=len-1)
                    pre->next = q.front();
                else
                    pre->next = nullptr;
                
                if(pre->left)
                    q.push(pre->left);
                if(pre->right)
                    q.push(pre->right);
                
            }
        }
        
        return root;
    }
    
};

#else


#endif
