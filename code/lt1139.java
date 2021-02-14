class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int rows = grid.length;
        if(rows == 0)
            return 0;
        int cols = grid[0].length;
        if(cols == 0)
            return 0;
        
        int maxLen = 0;
        int[][] dp = new int[rows][cols];
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0)
                    continue;

                int edge = 1;
                while(i + edge < rows && j + edge < cols && grid[i + edge][j] == 1  && grid[i][j + edge] == 1)
                    edge++;
                dp[i][j] = edge;
            }
        }

        for(int i = rows - 1; i >= 0; i--){
            for(int j = cols - 1; j >= 0; j--){
                if(grid[i][j] == 0)
                    continue;
                int edge = 1, maxEdge = 1;
                while(i - edge >= 0 && j - edge >= 0 && grid[i - edge][j] == 1 && grid[i][j - edge] == 1){
                    if(dp[i - edge][j - edge] >= edge + 1){
                        maxEdge = edge + 1;
                    }
                    edge++;
                }
                maxLen = Math.max(maxEdge, maxLen);
            }
        }

        return maxLen * maxLen;
    }
}