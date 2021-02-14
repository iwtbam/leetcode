// https://leetcode-cn.com/problems/delete-middle-node-lcci/
// delete middle node lcci
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
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;
        node->val = node->next->val;
        node->next = node->next->next; 
        delete next;  
    }
};