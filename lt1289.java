// https://leetcode-cn.com/problems/minimum-falling-path-sum-ii/
// minimum falling path sum ii
class Solution {
    public int minFallingPathSum(int[][] arr) {
        int rows = arr.length;
        int cols = arr[0].length;
        
        
        int[][] dp = new int[rows][cols];
        
        for(int i = 0; i < cols; i++)
            dp[0][i] = arr[0][i];
        
        for(int i = 1; i < rows; i++){
            for(int j = 0; j < cols; j++){
                
                int pre = Integer.MAX_VALUE;
                for(int k = 0; k < cols; k++){
                    if(k == j)
                        continue;
                    pre = Math.min(pre, dp[i - 1][k]);
                }
                dp[i][j] = pre + arr[i][j];
            }
        }
        
        // for(int i = 0; i < rows; i++){
        //     for(int j = 0; j < cols; j++)
        //         System.out.print(dp[i][j] + " ");
        //     System.out.println();
        // }
        
        int minSum = Integer.MAX_VALUE;
        
        for(int i = 0; i < cols; i++)
            minSum = Math.min(minSum, dp[rows - 1][i]);
        
        
        return minSum;
        
        
        // return helper(arr, 0, 0, new HashSet<>());
    }
    

}