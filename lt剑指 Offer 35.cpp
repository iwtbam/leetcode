// https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof/
// fu za lian biao de fu zhi lcof
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        Node* cur = head;
        while(cur != nullptr){
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }

        cur = head;

        while(cur != nullptr){
            if(cur->random != nullptr){
                cur->next->random = cur->random->next;
            }

            cur = cur->next->next;
        }

        Node* newHead = head->next;
        cur = head;
        while(cur != nullptr){
            Node* copy = cur->next;
            cur->next = copy->next;
            cur = copy->next;
            if(cur!= nullptr)
                copy->next = cur->next;
        }

        return newHead;
    }
};