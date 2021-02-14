class Solution {
    public String encode(String s) {
        int n = s.length();
        String[][] dp = new String[n][n];
        
        for(int len = 1; len <= n; len++){
            for(int i = 0; i < n - len + 1; i++){
                int j = i + len - 1;
                String t = s.substring(i, i + len);
                dp[i][j] = t;
                for(int k = i; k < j; k++){
                    if(dp[i][j].length() > dp[i][k].length() + dp[k+1][j].length())
                        dp[i][j] = dp[i][k] + dp[k+1][j];
                }
                
                int pos = (t + t).indexOf(t, 1);
                if(pos < t.length()){
                    String replace = (t.length() / pos) + "[" + dp[i][i + pos - 1] + "]";
                    if(replace.length() < dp[i][j].length())
                        dp[i][j] = replace;
                }                
               
            }
        }
            
        return dp[0][n-1];
    }
}