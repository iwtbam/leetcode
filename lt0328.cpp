// https://leetcode-cn.com/problems/odd-even-linked-list/
// odd even linked list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* oddHead = head;
        if(oddHead->next == nullptr)
            return oddHead;
        ListNode* evenHead = oddHead->next;
        ListNode* h1 = oddHead, *h2 = evenHead, *pre = nullptr;

        while(h2->next){
            h1->next = h2->next;
            pre = h1;
            h1 = h1->next;
            if(h1 == nullptr)
                break;
            h2->next = h1->next;
            h2 = h2->next;
            if(h2 == nullptr){
                pre = h1;
                break;
            }
        }
        // return oddHead;
        if(h1 == nullptr)
            pre->next = evenHead;
        else
            h1->next= evenHead;
        return oddHead;
    }
};