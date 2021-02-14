// https://leetcode-cn.com/problems/remove-duplicate-node-lcci/
// remove duplicate node lcci
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
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode* node = head;
        while(node != nullptr){
            ListNode* cur = node->next;
            ListNode* pre = node;
            while(cur != nullptr){
                if(node->val == cur->val){
                    pre->next = cur->next;
                    cur = pre->next;
                }else{
                    pre = cur;
                    cur = cur->next;
                }
             
            }
            node = node->next;
        }

        return head;
    }
};