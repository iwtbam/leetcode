import java.util.*;

class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head == null)
            return true;
        
        ListNode pre = null, cur = head, last = null;
        while(cur != null){
            last = cur;
            pres.put(cur, pre);
            pre = cur;
            cur = cur.next;
        }
        
        cur = head;
        
        while(cur!= null && last!= null && cur!=last){
            if(cur.val != last.val)
                return false;
            cur = cur.next;
            last = pres.get(last);
        }
        return true;
    }
    
    private Map<ListNode, ListNode> pres = new HashMap<>();
}