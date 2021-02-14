class Solution {
    public double probabilityOfHeads(double[] prob, int target) {
        
        int len = prob.length;
        
        double res = 1.0;
        
        if(target == 0){
            for(int i = 0; i < len; i++)
                res *=  (1 - prob[i]);
            return res;
        }
        
        double[][] dp = new double[len][target + 1];
        dp[0][0] = 1 - prob[0];
        dp[0][1] = prob[0];
        
        for(int i = 1; i < len; i++){
            for(int j = 1; j <= target && j <= (i + 1); j++){
                dp[i][j] = dp[i - 1][j - 1] * prob[i] + dp[i - 1][j] * (1 - prob[i]);
            }
            dp[i][0] = dp[i - 1][0] * (1 - prob[i]);
        }
        
        return  dp[len - 1][target];
    }
}