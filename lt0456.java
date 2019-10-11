import java.util.*;

class Solution {
    public boolean find132pattern(int[] nums) {
        int len = nums.length;
        int third = Integer.MIN_VALUE;
        Stack<Integer> max = new Stack<>();
        
        for(int i = len - 1; i >= 0; i--){
            if(nums[i] < third)
                return true;
            while(max.size() > 0 && nums[i] > max.peek()){
                third = max.pop();
            }
            max.push(nums[i]);
        }
        
        return false;
    }
}