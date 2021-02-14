import java.util.*;

class Solution {
    public boolean canDivideIntoSubsequences(int[] nums, int K) {
        
        Map<Integer, Integer> count = new HashMap<>();
        
        int len = nums.length;
        int maxSize = 0;
        for(int i = 0; i < len; i++){
            int size = count.getOrDefault(nums[i], 0) + 1;
            maxSize = Math.max(size, maxSize);
            count.put(nums[i], size);
        }
        
        if(maxSize * K > len)
            return false;
        
        return true;
    }
}