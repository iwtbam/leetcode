class ListNode {
    int val;
    ListNode next;
    ListNode(int x){ val = x;}
}

public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode head1 = headA, head2 = headB;
        int len1 = 0, len2 = 0;
        while(head1 != null){
            len1++;
            head1 = head1.next;
        }
        
        while(head2 != null){
            len2++;
            head2 = head2.next;
        }
        
        head1 = headA;
        head2 = headB;
  
        
        int offset = len1 - len2;
        if(offset < 0){
            offset = -offset;
            while(offset!=0&&head2!=null){
                offset -= 1;
                head2 = head2.next;
            }
        }else{
            while(offset!=0&&head1!=null){
                offset -= 1;
                head1 = head1.next;
            }
        }
        
        while(head1!=null && head2!=null){
            if(head1 == head2)
                return head1;
            head1 = head1.next;
            head2 = head2.next;
        }
        
        return null;
    }
}