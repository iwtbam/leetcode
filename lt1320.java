// https://leetcode-cn.com/problems/minimum-distance-to-type-a-word-using-two-fingers/
// minimum distance to type a word using two fingers
class Solution {
    public int minimumDistance(String word) {
        int len = word.length();
        int[][][] dp = new int[len + 1][26][26];

        for(int i = 1; i <= len; i++){
            for(int l = 0; l < 26; l++){
                for(int r = 0; r < 26; r++){
                    dp[i][l][r] = Integer.MAX_VALUE;
                }
            }
        }

        char[] chs = word.toCharArray();
        int ans = Integer.MAX_VALUE;

        for(int i = 1; i <= len; i++){
            int pos = chs[i - 1] - 'A';
            for(int l = 0; l < 26; l++){
                for(int r = 0; r < 26; r++){
                    if(dp[i - 1][l][r] != Integer.MAX_VALUE){
                        dp[i][pos][r] = Math.min(dp[i][pos][r], dp[i - 1][l][r] + dis(l, pos));
                        dp[i][l][pos] = Math.min(dp[i][l][pos], dp[i - 1][l][r] + dis(r, pos));
                    }

                    if(i == len){
                        ans = Math.min(ans, dp[i][pos][r]);
                        ans = Math.min(ans, dp[i][l][pos]);
                    }
                }
            }
        }
        return ans;
    }

    public int dis(int c1, int c2){
        return Math.abs(c1 % 6 - c2 % 6) + Math.abs(c1 / 6 - c2 / 6);
    }
}