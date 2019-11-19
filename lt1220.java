class Solution {
    public int countVowelPermutation(int n) {
        int[][] dp = new int[n][5];
        
        for(int i = 0; i < 5; i++)
            dp[0][i] = 1;
        
        for(int i = 1; i < n; i++){
            dp[i][0] = ((dp[i-1][1] + dp[i-1][2]) % MOD + dp[i-1][4]) % MOD;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
            dp[i][2] = (dp[i-1][1] + dp[i-1][3]) % MOD;
            dp[i][3] = dp[i-1][2] % MOD;
            dp[i][4] = (dp[i-1][2] + dp[i-1][3]) % MOD;
        }
        
        int sum = 0;
        
        for(int i = 0; i < 5; i++)
            sum = (sum + dp[n-1][i]) % MOD;
        
        return sum % MOD;
    }
    
    private final int MOD = (int)Math.pow(10, 9) + 7;
}