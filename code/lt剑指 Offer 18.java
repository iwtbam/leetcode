// https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
// shan chu lian biao de jie dian lcof
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

// n1 -> n2 -> n3 -> n4 -> n5
//        p    c     n

// p = n
// n1 -> n4 -> n5
class Solution {
    public ListNode deleteNode(ListNode head, int val) {
        ListNode dumpy = new ListNode(0);
        dumpy.next = head;
        ListNode cur = head;
        ListNode pre = dumpy;
        while(cur != null){
            if(cur.val == val){
                pre.next = cur.next;
                break;
            }
            pre = cur;
            cur = cur.next;
        }

        return dumpy.next;
        
    }
}