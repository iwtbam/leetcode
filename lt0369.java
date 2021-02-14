// https://leetcode-cn.com/problems/plus-one-linked-list/
// plus one linked list
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode plusOne(ListNode head) {
         if(head == null)
            return null;
        
        ListNode nHead = new ListNode(0), pre = nHead, cur = head, last = cur;
        nHead.next = head;
        
        pres.put(nHead, null);
        
        
        while(cur!=null){
            last = cur;
            pres.put(cur, pre);
            pre = cur;
            cur = cur.next;
        }
        
        int co = 1;
        while(last != null && co != 0){
            int val = last.val + co;
            co = val /10;
            val = val % 10;
            last.val = val;
            last = pres.get(last);
        }
        
        return nHead.val == 1 ? nHead : nHead.next;
    }
    
    private Map<ListNode, ListNode> pres = new HashMap<>();
}