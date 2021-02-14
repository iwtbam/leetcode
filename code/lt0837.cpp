// https://leetcode-cn.com/problems/new-21-game/
// new 21 game
class Solution {
public:
    double new21Game(int N, int K, int W) {
        
        double rate = 1.0 / W;
        
        
        if(K == 0){
           return 1.0;
        }
        
        vector<double> dp(K + W, 0);
        dp[0] = 1.0;
        double sum = dp[0];
        for(int i = 1; i < K + W; i++){
            dp[i] = sum * rate;
            if(i < K){
                sum += dp[i];
            }
            if(i >= W){
                sum -= dp[i - W];
            }
        }

        double res = 0.0;
        for(int i = K; i <= min(N, K + W - 1); i++) {
            res = res  + dp[i];
        }

        return res;
    }
};