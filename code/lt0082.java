class ListNode {
    int val;
    ListNode next;
    ListNode(int x){val = x;}
}


class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        
        if(head == null)
            return null;
        
        ListNode nHead = new ListNode(head.val + 1);
        nHead.next = head;
        ListNode cur = head, pre = nHead,  ppre = nHead;
        while(cur != null){
        
            if(!(pre.val == cur.val || (cur.next!=null && cur.val ==  cur.next.val))){
                ppre.next = cur;
                ppre = cur;              
            }
            
            pre = cur;            
            cur = cur.next;
        }
        
        ppre.next = null;
        return nHead.next;
    }
}