// https://leetcode-cn.com/problems/kth-node-from-end-of-list-lcci/
// kth node from end of list lcci
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
    int kthToLast(ListNode* head, int k) {
        ListNode* node = helper(head, k);
        return node->val;
    }

    ListNode* helper(ListNode* node, int& k){
        if(node == nullptr)
            return nullptr;
        ListNode* res = helper(node->next, k);
        if(res != nullptr)
            return res; 
        k--;
        if(k == 0)
            return node;
        return nullptr;
    }
};