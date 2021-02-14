// https://leetcode-cn.com/problems/convert-binary-number-in-a-linked-list-to-integer/
// convert binary number in a linked list to integer
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int getDecimalValue(ListNode head) {
        int res = 0;
        while(head != null){
            res = res * 2 + head.val;
            head = head.next;
        }
        return res;
    }
}