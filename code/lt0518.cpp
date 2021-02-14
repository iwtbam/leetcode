// https://leetcode-cn.com/problems/coin-change-2/
// coin change 2
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        size_t size = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < size; i++){
            for(int v = coins[i]; v <= amount; v++){
                dp[v] = dp[v] + dp[v - coins[i]];
            }
        }

        return dp[amount];
    }
};