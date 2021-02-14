// https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
// liang ge lian biao de di yi ge gong gong jie dian lcof
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA, *p2 = headB;

        int len1 = 0, len2 = 0;

        while(p1 != nullptr){
            p1 = p1->next;
            len1++;
        }

        while(p2 != nullptr){
            p2 = p2->next;
            len2++;
        }

        p1 = len1 > len2 ? headA : headB;
        p2 = len1 > len2 ? headB : headA;

        int diff = max(len1, len2) - min(len1, len2);

        while(p1 && diff){
            diff--;
            p1 = p1->next;
        }

        while(p1 != nullptr && p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }
};