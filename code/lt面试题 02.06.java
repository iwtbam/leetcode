// https://leetcode-cn.com/problems/palindrome-linked-list-lcci/
// palindrome linked list lcci
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        int len = 0;
       
        ListNode cur = head;
        while(cur != null){
            cur = cur.next;
            len++;
        }

        int half = len >> 1;

        ListNode former = head;
        ListNode latter = head;
        
        int step = 0;
        while(step < half){
            step++;
            latter = latter.next;
        }

        ListNode pre = null;
        while(latter != null){
            ListNode next = latter.next;
            latter.next = pre;
            pre = latter;
            latter = next;
        }

        latter = pre;
        while(former != null && latter != null){
            if(former.val != latter.val)
                return false;
            former = former.next;
            latter = latter.next;
        }

        return true;
    }
}