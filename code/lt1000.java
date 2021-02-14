import java.util.*;

class Solution {
    public int mergeStones(int[] stones, int K) {
        int len = stones.length;

        if((len - 1) % (K - 1) != 0)
            return -1;

        int[][] dp = new int[len][len];
        int[] sums = new int[len + 1];

        for(int i = 1; i <= len; i++)
            sums[i] = sums[i - 1] + stones[i - 1];

        for(int i = 0; i < len; i++)
            Arrays.fill(dp[i], UN_SOLVED);

        for(int i = 0; i < len; i++)
            dp[i][i] = 0;

        for(int l = 2; l <= len; l++){
            for(int i = 0; i < len - l + 1; i++){
                int j = i + l - 1;
                
                for(int m = i; m < j; m += K - 1)
                    dp[i][j] = Math.min(dp[i][j], dp[i][m] + dp[m + 1][j]);
                
                if((l - 1) % (K - 1) == 0 && dp[i][j] < UN_SOLVED)
                    dp[i][j] = dp[i][j] + sums[j + 1] - sums[i];
            }
        }

        return dp[0][len - 1];
    }

    private final int UN_SOLVED = Integer.MAX_VALUE / 2;
}