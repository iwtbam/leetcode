/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

class ListNode{
     int val;
     ListNode next;
     ListNode(int x){val = x;};
 }

 class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        
        if(head == null)
            return null;
        
        ListNode pre = head, pHead = head;
        ListNode pStart = head;
        while(pStart!=null){
            int sum = pStart.val;
            ListNode pEnd = pStart.next;
            while(pEnd != null && sum != 0){
                sum += pEnd.val;
                pEnd = pEnd.next;
            }


            if(sum == 0){
                if(pre == pStart){
                    pre = pEnd;
                    pHead = pEnd;
                }else{
                    pre.next = pEnd;
                }
                pStart = pEnd;                
            }else{
                pre = pStart;
                pStart = pStart.next;
            }

        }
        return pHead;
    }
}