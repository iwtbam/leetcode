class ListNode {
    int val;
    ListNode next;
    ListNode(int x){ val = x;}
}

class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode ltHead = new ListNode(0), lt = ltHead;
        ListNode gtHead = new ListNode(0), gt = gtHead;
        ListNode node = head;
        while(node != null){
            if(node.val >= x){
                gt.next = node;
                gt = node;
            }else{
                lt.next = node;
                lt = node;
            }
            
            node = node.next;
        }
        
        gt.next = null;
        lt.next = gtHead.next;
        return ltHead.next;
    }
}