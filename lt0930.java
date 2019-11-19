import java.util.*;

class Solution {
    public int numSubarraysWithSum(int[] A, int S) {
        int len = A.length;
        if(len == 0)
            return 0;
        
        Map<Integer, Integer> record = new HashMap<>();
        record.put(0, 1);
        int sum   = 0;
        int count = 0;
        for(int i = 0; i < len; i++){
            sum += A[i];
            if(record.containsKey(sum - S))
                count += record.get(sum - S);
            
            record.put(sum, record.getOrDefault(sum, 0) + 1);
        }
        
        return count;
    }
}