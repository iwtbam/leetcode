class ListNode {
    int val;
    ListNode next;
    ListNode(int x){val = x;}
}


class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        ListNode node = head, oldTail = null;
        int nodeNum = 0;
        
        while(node != null){
            oldTail = node;
            nodeNum++;
            node = node.next;
        }
        
        if(oldTail == null)
            return null;
       
        
        k = k % nodeNum;
        
        if(k==0)
            return head;
        
        ListNode newTail = null, newHead = head;
        int step = 0;
       
        while(newHead != null && step < nodeNum - k){
            step++;
            newTail = newHead;
            newHead = newTail.next;
        }
        
        newHead = newTail.next;
        oldTail.next = head;
        newTail.next = null;
        
        return newHead;
    }
}