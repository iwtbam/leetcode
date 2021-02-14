// https://leetcode-cn.com/problems/merge-k-sorted-lists/
// merge k sorted lists
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0)
            return null;
        return mergeKLists(lists, 0, lists.length);
    }

    public ListNode mergeKLists(ListNode[] lists, int start, int end){
        if(end - start == 1)
            return lists[start];
        
        int mid = (start + end) >> 1;

        ListNode left  = mergeKLists(lists, start, mid);
        ListNode right = mergeKLists(lists, mid, end);
        return mergeList(left, right);
    }


    public ListNode mergeList(ListNode l1, ListNode l2){
        ListNode dumpy = new ListNode(0);
        ListNode cur   = dumpy;
        while(l1 != null &&  l2 != null){
            if(l1.val < l2.val){
                cur.next = l1;
                l1 = l1.next;
            }else{
                cur.next = l2;
                l2 = l2.next;
            }
            cur = cur.next;
        }

        ListNode l = l1 == null ? l2 : l1;
        cur.next = l;
        return dumpy.next;
    }

// 包访问权限

}