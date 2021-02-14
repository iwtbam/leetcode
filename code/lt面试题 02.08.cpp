// https://leetcode-cn.com/problems/linked-list-cycle-lcci/
// linked list cycle lcci
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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
            return nullptr;
        ListNode* slow = head->next;
        if(slow == nullptr)
            return nullptr;
        ListNode* fast = slow->next;

        while(fast && slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast == nullptr)
                return nullptr;
            fast = fast->next;
        }

        if(fast == nullptr)
            return nullptr;



        fast = head;

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;

    }
};