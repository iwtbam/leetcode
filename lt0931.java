class Solution {
    public int minFallingPathSum(int[][] A) {
        int rows = A.length;
        int cols = A[0].length;
        
        int[][] dp = new int[rows][cols];
        
        for(int i = 0; i < cols; i++)
            dp[0][i] = A[0][i];
        
        for(int i = 1; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int leftUp  =  j - 1 >= 0   ? dp[i - 1][j - 1] : Integer.MAX_VALUE;
                int rightUp =  j + 1 < cols ? dp[i - 1][j + 1] : Integer.MAX_VALUE;
                dp[i][j] = Math.min(dp[i-1][j], Math.min(leftUp, rightUp)) + A[i][j];
            }
        }
        
        
        int res = Integer.MAX_VALUE;
        for(int i = 0; i < cols; i++)
            res = Math.min(res, dp[rows - 1][i]);
        
        return res;
    }
}