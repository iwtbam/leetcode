// https://leetcode-cn.com/problems/soup-servings/
// soup servings
class Solution {
    public double soupServings(int N) {

        if(N >= 4800)
            return 1.0;

        int disN = (int)Math.ceil(N / 25.0);
        double[][] dp = new double[disN + 1][disN + 1];
        
        for(int i = 1; i <= disN; i++){
            dp[i][0] = 0;
            dp[0][i] = 1;
        }

        dp[0][0] = 0.5;

        for(int i = 1; i<= disN; i++){
            for(int j = 1; j <= disN; j++){
                dp[i][j] = 0.25 * (dp[relu(i - 4)][j] + dp[relu(i - 3)][relu(j - 1)] + dp[relu(i - 2)][relu(j - 2)] + dp[relu(i - 1)][relu(j - 3)]);
            }
        }

        return dp[disN][disN];
    }

    public int relu(int x){
        return Math.max(0, x);
    }
}