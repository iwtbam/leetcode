// https://leetcode-cn.com/problems/strange-printer/
// strange printer
class Solution {
    public int strangePrinter(String s) {
        int L = s.length();

        if(L == 0)
            return 0;

        int[][] dp = new int[L][L];

        char[] chs = s.toCharArray();
        
        for(int i = 0; i < L; i++)
            dp[i][i] = 1;

        for(int l = 2; l <= L; l++){
            for(int i = 0; i < L - l + 1; i++){
                int j = i + l - 1;
                dp[i][j] = dp[i + 1][j] + 1;
                for(int k = i + 1; k <= j; k++){
                    if(chs[k] == chs[i])
                        dp[i][j] = Math.min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                }
            }
        }

        return dp[0][L - 1];
    }
}