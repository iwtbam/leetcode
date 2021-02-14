// https://leetcode-cn.com/problems/minimum-difficulty-of-a-job-schedule/
// minimum difficulty of a job schedule
class Solution {
    public int minDifficulty(int[] jobDifficulty, int d) {
        int size = jobDifficulty.length;
        int[][] dp = new int[d][size];

        for(int i = 0; i < d; i++)
            Arrays.fill(dp[i], INF);

        int min_diff = jobDifficulty[0];
        
        for(int i = 0; i < size; i++){
            min_diff =  Math.max(min_diff, jobDifficulty[i]);
            dp[0][i] = min_diff;
        }
        for(int i = 1; i < d; i++){
            for(int j = i; j < size; j++){
                min_diff = jobDifficulty[j];
                for(int k = j; k >= i; k--){
                    min_diff = Math.max(jobDifficulty[k], min_diff);
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][k - 1] + min_diff);
                }
            }
        }

        return dp[d - 1][size - 1] == INF ? -1: dp[d - 1][size - 1]; 
    }

    private static final int INF = Integer.MAX_VALUE / 2 - 1;
}