class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int len = strs.length;
        int[][] record = new int[len][2];
        for(int i = 0; i < len; i++){
            int len2 = strs[i].length();
            for(int j = 0; j < len2; j++){
                record[i][strs[i].charAt(j) - '0']++;
            }
        }
        
        int[][] dp = new int[m+1][n+1];
              
        for(int i = 0; i < len; i++){
            for(int j = m; j >= record[i][0]; j--){
                for(int k = n; k >= record[i][1]; k--){
                    dp[j][k] = Math.max(dp[j][k], dp[j - record[i][0]][k - record[i][1]] + 1);
                }
            }
        }  
        return dp[m][n];
    }
}