// https://leetcode-cn.com/problems/k-inverse-pairs-array/
// k inverse pairs array
class Solution {
    public int kInversePairs(int n, int k) {
        int[][] dp = new int[n + 1][k + 1];
        dp[0][0] = 1;
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k && j <= (i + 1) * i/2; j++){
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
                if(j >= i)
                    dp[i][j] -= dp[i - 1][j - i];
                dp[i][j] = (dp[i][j] + MOD) % MOD;
            }
        }

        return dp[n][k];
    }

    private final int MOD = (int)Math.pow(10, 9) + 7;
}