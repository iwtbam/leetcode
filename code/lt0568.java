// https://leetcode-cn.com/problems/maximum-vacation-days/
// maximum vacation days
class Solution {
    public int maxVacationDays(int[][] flights, int[][] days) {
        int N = flights.length;
        if(N == 0)
            return 0;
        int K = days[0].length;
        
        int[][] dp = new int[N][K]; // dp[i][j] i 个 城市 第 j 星期可以获得的最大休假天数
    
        for(int i = 0; i < N; i++)
            dp[i][0] = flights[0][i] == 1 ? days[i][0] : 0;
        
        dp[0][0] = days[0][0];
        
        for(int j = 1; j < K; j++){
            for(int i = 0; i < N; i++){
                
                for(int k = 0; k < N; k++){
                    if(i!=k && flights[i][k]==0)
                        continue;
                    int mD = dp[i][j-1] == 0 ? 0 : dp[i][j-1] + days[k][j];
                    dp[k][j] = Math.max(dp[k][j], mD); 
                }
            }
        }
        
        int maxDays = -1;   
        for(int i = 0; i < N; i++){
            maxDays = Math.max(maxDays, dp[i][K-1]);
        }
        
        return maxDays;
    }
}