import java.util.*;

class Solution {
    public boolean isReflected(int[][] points) {
        Map<Integer, Set<Integer>> record = new HashMap<>();
        int left = Integer.MAX_VALUE, right = Integer.MIN_VALUE;
        for(int[] point: points){
            if(!record.containsKey(point[0]))
                record.put(point[0], new HashSet<Integer>());
            record.get(point[0]).add(point[1]);
            left = Math.min(left, point[0]);
            right = Math.max(right, point[0]);
        }
        
        int M = left + right;
        
        for(int[] point: points){
            if(!record.containsKey(M - point[0]))
                return false;
            
            if(!record.get(M - point[0]).contains(point[1]))
                return false;
        }

        return true;
    }
    
}