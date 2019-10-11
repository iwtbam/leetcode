class NumMatrix {

    public NumMatrix(int[][] matrix) {
        int rows = matrix.length;
        
        if(rows == 0)
            return;

        int cols = matrix[0].length;

        if(cols == 0)
            return;
        dp = new int[rows + 1][cols + 1];

        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= cols; j++){
                dp[i][j] = matrix[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
        
        
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        if(dp == null)
            return 0;
        
        int res = dp[row2+1][col2+1] + dp[row1][col1] - dp[row1][col2+1] - dp[row2+1][col1];
        return res;
    }
    
    
    private int[][] dp = null;
  
}