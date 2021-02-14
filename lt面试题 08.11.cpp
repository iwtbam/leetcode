// https://leetcode-cn.com/problems/coin-lcci/
// coin lcci
class Solution {
public:
    int waysToChange(int n) {
        vector<int> dp(n + 1, 0);
        vector<int> coins = {1, 5, 10, 25};

        const int MOD = pow(10, 9) + 7;

        dp[0] = 1;

        for(int i = 0; i < 4; i++){
            for(int cost = coins[i]; cost <= n; cost++){
                dp[cost] = (dp[cost] + dp[cost - coins[i]]) % MOD;
            }
        }

        return dp[n];
    }
};