import java.util.*;

class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int len = A.length;
        Map<Integer, Integer>[] dp = new Map[len];
        int total = 0;
        for(int i = 0; i < len; i++){
            dp[i] = new HashMap<Integer, Integer>();
            for(int j = 0; j < i; j++){
                long diff = (long)A[i] - (long)A[j];
                if(diff < Integer.MIN_VALUE || diff > Integer.MAX_VALUE)
                    continue;
                int pre = dp[j].getOrDefault((int)diff, 0);
                int cur = dp[i].getOrDefault((int)diff, 0);
                dp[i].put((int)diff, cur + pre + 1);
                total += pre;
            }
        }
        return total;
    }
}