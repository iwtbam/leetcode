class Solution {
    public int minimumMoves(int[][] grid) {
        int n = grid.length;
        int[][][] dp = new int[n][n][2];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < 2; k++)
                    dp[i][j][k] = UN_SOLVED;
            }
        }
        
        
        dp[0][0][0] = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                
                if(grid[i][j]==1)
                    continue;
                
                if(i < n - 1 && j < n - 1 && grid[i][j + 1] == 0 && grid[i + 1][j] == 0 && grid[i + 1][j + 1] == 0){
                    dp[i][j][0] = Math.min(dp[i][j][0], dp[i][j][1] + 1);
                    dp[i][j][1] = Math.min(dp[i][j][1], dp[i][j][0] + 1);
                    dp[i + 1][j][0] = Math.min(dp[i + 1][j][0], dp[i][j][0] + 1);
                    dp[i][j + 1][1] = Math.min(dp[i][j + 1][1], dp[i][j][1] + 1);
                }
                
                if(i < n - 2 && grid[i+1][j] == 0 && grid[i+2][j] == 0)
                    dp[i + 1][j][1] = Math.min(dp[i + 1][j][1], dp[i][j][1] + 1);
                
                if(j < n - 2 && grid[i][j+1] == 0 && grid[i][j+2] == 0)
                    dp[i][j + 1][0] = Math.min(dp[i][j + 1][0], dp[i][j][0] + 1);
            }
        }
        
        int res = dp[n-1][n-2][0];
        
        return res == UN_SOLVED ? -1 : res;
    }
    
    public final int UN_SOLVED = Integer.MAX_VALUE / 2;
    
}