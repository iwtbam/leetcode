// https://leetcode-cn.com/problems/partition-list-lcci/
// partition list lcci
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
    ListNode* partition(ListNode* head, int x) {
       ListNode* pre = head;
       ListNode* cur = head;
       while(cur){
           if(cur->val < x){
               int temp = pre->val;
               pre->val = cur->val;
               cur->val = temp;
               pre = pre->next;
           }
           cur = cur->next;
       }
       return head;
    }
};