// https://leetcode-cn.com/problems/linked-list-cycle/
// linked list cycle
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null)
            return false;
        ListNode slow = head;
        if(slow.next == null)
            return false;
        ListNode fast = slow.next;
        while(fast != slow){
            if(fast.next == null || fast.next.next == null)
                return false;
            fast = fast.next.next;
            slow = slow.next;
        }
        return true;
    }
}