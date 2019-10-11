class Solution {
    public int numDistinct(String s, String t) {
        int len1 = s.length();
        int len2 = t.length();
        int[][] dp = new int[len1+1][len2+1];
        dp[0][0] = 1;

        for(int i = 1; i <= len1; i++)
            dp[i][0] = 1;

        for(int i = 1; i <= len2; i++)
            dp[0][i] = 0;

        for(int i = 1; i <= len1; i++){
            for(int j = 1; j<=len2;j++){
                dp[i][j] = dp[i-1][j];
                if(s.charAt(i-1) == t.charAt(j-1))
                    dp[i][j] += dp[i-1][j-1];
                
            }
        }

        
        return dp[len1][len2];
    }
}