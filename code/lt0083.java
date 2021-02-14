class ListNode {
    int val;
    ListNode next;
    ListNode(int x){ val = x;}
}

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        
        ListNode cur = head;
        if(cur == null)
            return head;
        
        ListNode next = cur.next;
        while(next!=null){
            if(next.val != cur.val){
                cur.next = next;
                cur = next;
            }
            next = next.next;
        }
        
        cur.next = null;
        
        return head;
    }
}