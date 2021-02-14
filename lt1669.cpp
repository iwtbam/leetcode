// https://leetcode-cn.com/problems/merge-in-between-linked-lists/
// merge in between linked lists
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        
        ListNode* pre = nullptr,  *p1 = list1;
        ListNode* pTail = nullptr, *pHead = list2, *p2 = list2;
        
        while(p2 != nullptr){
            pTail = p2;
            p2 = p2->next;
        }
        
        int pos = 0;
        while(p1 != nullptr){
            
            if(pos == a)
                pre->next = pHead;
            
            if(pos == b){
                pTail->next = p1->next;
                break;
            }
            pre = p1;
            p1 = p1->next;

            pos++;
        }
        
        
        return list1;
    }
};