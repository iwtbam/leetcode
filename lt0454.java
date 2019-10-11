import java.util.*;


class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        Map<Integer, Integer> record = new HashMap<>();
        int res = 0;
        for(int a: A){
            for(int b: B){
                int sum = a + b;
                record.put(sum, record.getOrDefault(sum, 0) + 1);
            }
        }
        
        for(int c: C){
            for(int d : D){
                res += record.getOrDefault(-(c+d), 0);
            }
        }
        
        return res;
    }
}