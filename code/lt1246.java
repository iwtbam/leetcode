class Solution {
    public int minimumMoves(int[] arr) {
        int len = arr.length;
        int[][] dp = new int[len][len];
        for(int i = 0; i < len; i++)
            dp[i][i] = 1;
        
        for(int i = 0; i < len - 1; i++){
            dp[i][i + 1] = arr[i] == arr[i + 1] ? 1 : 2;
        }
        
        for(int l = 3; l <= len; l++){
            for(int i = 0; i < len - l + 1; i++){
                int e = i + l - 1;
                dp[i][e] = Integer.MAX_VALUE;
                for(int k = i; k < e; k++){
                    if(dp[i][e] > dp[i][k] + dp[k + 1][e])
                        dp[i][e] = dp[i][k] + dp[k + 1][e];
                }
                
                if(arr[i] == arr[e] && dp[i][e] > dp[i + 1][e - 1] )
                    dp[i][e] = dp[i + 1][e - 1];
            }
        }
        
        return dp[0][len - 1];
    }
}