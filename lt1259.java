class Solution {
    public int numberOfWays(int num_people) {
        long[] dp = new long[num_people + 1];
        if(num_people == 2)
            return 1;
        dp[0] = 1;
        dp[2] = 1;
        // dp[4] = 2;
        
        for(int i = 4; i <= num_people; i++){
            for(int j = 0; j <= i - 2; j++){
                dp[i] += (dp[j] * dp[i - j - 2]) % MOD;
            }
            dp[i] = (dp[i]) % MOD;
        } 

        return (int)dp[num_people] % MOD;
    }

    private final int MOD = (int)Math.pow(10, 9) + 7;
}