// https://leetcode-cn.com/problems/swapping-nodes-in-a-linked-list/
// swapping nodes in a linked list
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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == nullptr)
            return head;
        ListNode* cur = head, *pre = nullptr;
        while(k-- && cur){
            pre = cur;
            cur = cur->next;
        }
        
        ListNode *f = pre, *fast = pre, *slow = head;
        while(fast->next!= nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        swap(f->val, slow->val);
        return head;
    }
};