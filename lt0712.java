class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        
        int len1 = s1.length();
        int len2 = s2.length();
        
        int[][] dp = new int[len1 + 1][len2 + 1];
        
        for(int i = len1 - 1; i >= 0; i--)
            dp[i][len2] = dp[i+1][len2] + s1.codePointAt(i);
        
        for(int i = len2 - 1; i >= 0; i--)
            dp[len1][i] = dp[len1][i+1] + s2.codePointAt(i);
        
        
        for(int i = len1 - 1; i >= 0; i--){
            for(int j = len2 - 1; j >= 0;j--){
                if(s1.charAt(i) == s2.charAt(j))
                    dp[i][j] = dp[i+1][j+1];
                else
                    dp[i][j] = Math.min(dp[i+1][j] +  s1.codePointAt(i), dp[i][j+1] + s2.codePointAt(j));
            }
        }
        
        
        return dp[0][0];
    }
}