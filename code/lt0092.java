class ListNode {
    int val;
    ListNode next;
    ListNode(int x){ val = x;}
}


class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode nHead = new ListNode(0);
        ListNode pre = nHead;
        nHead.next = head;
        ListNode cur = head;
        ListNode mPre = null, mCur = null;
        int step = 0;
        while(cur!=null){
            step++;
            if(step == m){
                mPre = pre;
                mCur = cur;
                break;
            }
            pre = cur;
            cur = cur.next;
        }
        
        while(cur!=null && step <= n){
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
            step++;
        }
        
        mPre.next = pre;
        mCur.next = cur;
        
        return nHead.next;
    }
}