import java.util.*;

class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int len = nums.length;
        
        if(len == 0)
            return new int[0];
        
        int last = nums[len - 1];
        Stack<Integer> record = new Stack<>();
        
        for(int i = len - 2; i >= 0; i--){
            if(nums[i] > last){
                record.push(nums[i]);
            }
        }
        
        int[] res = new int[len];
        
        for(int i = len - 1; i >= 0; i--){
            while(record.size() > 0 && record.peek() <= nums[i]){
                record.pop();
            }
            
            res[i] = record.size() == 0 ? -1 : record.peek();
            record.push(nums[i]);
        }
        
        return res;        
    }
}