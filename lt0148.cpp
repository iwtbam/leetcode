/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int len = length(head);
        return sortList(head, len);
    }

    ListNode* sortList(ListNode* node, int len){
        if(len == 0)
            return nullptr;

        if(len == 1){
            node->next = nullptr;
            return node;
        }
        int half = len / 2;
        ListNode* former = node;
        ListNode* later  = forward(node, half);
        former = sortList(former, half);
        later  = sortList(later,  len - half);
        return merge(former, half, later, len - half); 
    }


    ListNode* merge(ListNode* node1, int len1, ListNode* node2, int len2){
        ListNode head = {0};
        ListNode* cur = &head;
        while(len1 && len2){
            if(node1->val > node2->val){
                cur->next = node2;
                node2 = node2->next;
                len2--;
            }else{
                cur->next = node1;
                node1 = node1->next;
                len1--;
            }
            cur = cur->next;
        }
        cur->next = len1 ? node1 : node2;        
        return head.next;
    }

    int length(ListNode* node){
        int len = 0;
        while(node!=nullptr){
            len++;
            node = node->next;
        }
        return len;
    }

    ListNode* forward(ListNode* node, size_t n){
        while(n && node){
            n--;
            node = node->next;
        }
        return node;
    }
};