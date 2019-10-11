#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 

// 双指针，一次遍历

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pHead1 = head;
        int step = n + 1;
        
        while(pHead1 && step--)
            pHead1 = pHead1->next;
     
        ListNode* pHead2 = head;
        
        if(pHead1 == nullptr && step == 1)
        {
            head = head->next;
            return head;
        }

        while(pHead1)
        {
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        
        if(pHead2 == nullptr)
            return head;
        
        pHead1 = pHead2->next;
        if(n > 1)
            pHead2->next = pHead1->next;
        else
            pHead2->next = nullptr;
        
        
        return head;   
    }
}