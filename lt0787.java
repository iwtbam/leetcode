import java.util.*;

class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        int[][] dp = new int[n][K+2];
        for(int i = 0; i < n; i++)
            Arrays.fill(dp[i], UN_REACH);
        for(int k = 0; k <= K+1; k++)
            dp[src][k] = 0;
        
        for(int k = 1; k <= K+1; ++k){
            for(int[] flight : flights){
                if(dp[flight[0]][k-1] != UN_REACH)
                    dp[flight[1]][k] = Math.min(dp[flight[1]][k], dp[flight[0]][k-1] + flight[2]);
            }
        }
        
        return dp[dst][K+1] == UN_REACH ? -1 : dp[dst][K+1];
    }
    
    public final int UN_REACH = Integer.MAX_VALUE / 2;
}