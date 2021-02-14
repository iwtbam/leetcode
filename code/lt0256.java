// class Solution1 {
//     public int minCost(int[][] costs) {
//         int n = costs.length;
        
//         if(n == 0)
//             return 0;
        
//         int[][] dp = new int[n][3];
//         dp[0][0] = costs[0][0];
//         dp[0][1] = costs[0][1];
//         dp[0][2] = costs[0][2];
        
//         for(int i = 1; i < n; i++){
//             dp[i][0] = Math.min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
//             dp[i][1] = Math.min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
//             dp[i][2] = Math.min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
//         }
        
//         return Math.min(dp[n-1][0], Math.min(dp[n-1][1], dp[n-1][2]));
//     }
// }

class Solution {
    public int minCost(int[][] costs) {
        int n = costs.length;
        
        if(n == 0)
            return 0;
        
        int dp00,dp01, dp02, dpi0,dpi1, dpi2;
        dp00 = costs[0][0];
        dp01 = costs[0][1];
        dp02 = costs[0][2];
        
        for(int i = 1; i < n; i++){
            dpi0 = Math.min(dp01, dp02) + costs[i][0];
            dpi1 = Math.min(dp00, dp02) + costs[i][1];
            dpi2 = Math.min(dp00, dp01) + costs[i][2];
            dp00 = dpi0;
            dp01 = dpi1;
            dp02 = dpi2;
        }
        
        return Math.min(dp00, Math.min(dp01, dp02));
    }
}