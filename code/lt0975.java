import java.util.*;

class Solution {
    public int oddEvenJumps(int[] A) {
        int len = A.length;
        if(len == 0)
            return 0;
        int[][] dp = new int[len][2];
        dp[len - 1][0] = 1;
        dp[len - 1][1] = 1;

        TreeMap<Integer, Integer> record = new TreeMap<>();
        record.put(A[len - 1], len - 1);

        int ans = 1;

        for(int i = len - 2; i >= 0; i--){
            Integer key = record.ceilingKey(A[i]);
            if(key != null && dp[record.get(key)][1] == 1){
                dp[i][0] = 1;
                ans++;
            }
            key = record.floorKey(A[i]);
            if(key != null && dp[record.get(key)][0] == 1)
                dp[i][1] = 1;
            record.put(A[i], i);
        }

        return ans;
    }
}