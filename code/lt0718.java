class Solution {
    public int findLength(int[] A, int[] B) {
        int len1 = A.length;
        int len2 = B.length;
        if(len1 == 0 || len2 == 0)
            return 0;
        
        int[][] dp = new int[len1][len2];
        int maxLen = 0;
        for(int i = 0; i < len1; i++){
            for(int j = 0; j < len2; j++){
                if(A[i] == B[j]){
                    dp[i][j] = (i > 0 && j > 0) ? dp[i-1][j-1] + 1: 1;
                }else{
                    dp[i][j] = 0;
                }
                
                maxLen = Math.max(maxLen, dp[i][j]);
            }
        }
        
        return maxLen;
    
    }
}