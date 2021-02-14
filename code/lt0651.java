class Solution {
    public int maxA(int N) {
        
     
        int[][] dp = new int[N][4];
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 0;
        
        for(int i = 1; i < N; i++){ 
            dp[i][0] = maxArr(dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i-1][3]) + 1;
            dp[i][1] = maxArr(dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i-1][3]);
            dp[i][2] = dp[i-1][1];
            dp[i][3] = dp[i-1][2] * 2;
            for(int j = 0; j < i - 1; j++)
                dp[i][3] = Math.max(dp[i][3], dp[j][2] * (i - j + 1));
         
        }
        
        
        return maxArr(dp[N-1][0], dp[N-1][1], dp[N-1][2], dp[N-1][3]);
    }
    
    public int maxArr(Integer... arrs){
        int res = arrs[0];
        for(int i = 1; i < arrs.length; i++)
            res = Math.max(res, arrs[i]);
        return res;
    }
}