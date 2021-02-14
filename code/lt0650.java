class Solution {
    public int minSteps(int n) {
        
        if(n == 1)
            return 0;
        
        int[] dp = new int[n+1];
        
        
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i <= n; i++){
            dp[i] = i;
            for(int j = 2; j < i; j++){
                if(i % j == 0)
                    dp[i] = Math.min(dp[i], dp[j] + i / j);
            }
        }
        
        return dp[n];
    }
}