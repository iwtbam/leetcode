// https://leetcode-cn.com/problems/sum-lists-lcci/
// sum lists lcci
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dumpy;
        ListNode* cur = &dumpy;

        int co = 0, val1 = 0, val2 = 0;

        while(l1 || l2 || co){
            int val1 = 0, val2 = 0;
            if(l1 != nullptr){
                val1 = l1->val;
                l1 = l1->next;
            }

            if(l2 != nullptr){
                val2 = l2->val;
                l2 = l2->next;
            }
            int val = val1 + val2 + co;
            co = val / 10;
            val = val % 10;
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        
        return dumpy.next;
    }
};