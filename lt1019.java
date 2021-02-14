// https://leetcode-cn.com/problems/next-greater-node-in-linked-list/
// next greater node in linked list
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int[] nextLargerNodes(ListNode head) {
        ArrayList<Integer> nums = new ArrayList<>();
        
        while(head!=null){
            nums.add(head.val);
            head = head.next;
        }
        
        int size = nums.size();
        int[] res = new int[size];
        
        Stack<Integer> larger = new Stack<Integer>();
        
        for(int i = size - 1; i >= 0; i--){
            
            while(larger.size() != 0 && larger.peek() <= nums.get(i)){
                larger.pop();
            }
            
            if(larger.size() == 0)
                res[i] = 0;
            else{
                res[i] = larger.peek();
            }
            
            larger.push(nums.get(i));
        }
        
        return res;
        
    }
}