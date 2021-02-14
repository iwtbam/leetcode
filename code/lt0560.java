import java.util.*;

class Solution {
    public int subarraySum(int[] nums, int k) {
      
        int len = nums.length;
        
        if(len == 0)
            return 0;
        
        Map<Integer, Integer> memos = new HashMap<>();
        memos.put(0, 1);
        int sum = 0, count = 0;
        for(int i = 0; i < len; i++){
            sum += nums[i];
            if(memos.containsKey(sum - k))
                count += memos.get(sum - k);
            memos.put(sum, memos.getOrDefault(sum, 0) + 1);
        }
        
        return count;
        
    }
}