import java.util.*;


class ListNode {
     int val;
     ListNode next;
     ListNode(int x){ val = x;}
}

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        Stack<Integer> s1 = convert(l1);
        Stack<Integer> s2 = convert(l2);
        
        int co = 0;
        
        ListNode head = new ListNode(0);
        
        while(s1.size() > 0 && s2.size() > 0){
            int val = s1.pop() + s2.pop() + co;
            co = val / 10;
            val = val % 10;
            head.val = val;
            ListNode node = new ListNode(0);
            node.next = head;
            head = node;
        }
        
        Stack<Integer> s = s1.size() > 0 ? s1 : s2;
        
        while(s.size() > 0){
            int val = s.pop() + co;
            co =  val / 10;
            val = val % 10;
            head.val = val;
            ListNode node =new ListNode(0);
            node.next = head;
            head = node;
        }
        
        if(co == 1){
            head.val = co;
            ListNode node =new ListNode(0);
            node.next = head;
            head = node;            
        }
        return head.next;
    }
    
    public Stack<Integer> convert(ListNode l){
        Stack<Integer> s = new Stack<Integer>();
        while(l != null){
            s.push(l.val);
            l = l.next;
        }
        return s;
    }
}