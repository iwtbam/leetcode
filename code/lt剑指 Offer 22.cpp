// https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
// lian biao zhong dao shu di kge jie dian lcof
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
    ListNode* getKthFromEnd(ListNode* head, int k) {

        ListNode *slow = head, *fast = head;
        while(k >= 1 && fast!=nullptr){
            k--;
            fast = fast->next;
        }

        while(fast!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};