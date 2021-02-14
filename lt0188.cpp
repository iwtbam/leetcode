// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
// best time to buy and sell stock iv
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int day = prices.size();
        if(day < 2)
            return 0;

        if(k > day / 2)
            return helper(prices);

        vector<vector<vector<int>>> dp = {day, {k + 1, vector<int>(2, 0)}};
        
        for(int i = 0; i <= k; i++){
            dp[0][i][0] = 0;
            dp[0][i][1] = -prices[0];
        }

        for(int i = 1; i < day; i++){
            for(int j = 1; j <=k; j++){
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }

        return dp[day - 1][k][0];
    }

    int helper(vector<int>& prices){
        int day = prices.size();
        vector<vector<int>> dp = {day, vector<int>(2, 0)};
        
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for(int i = 1; i < day; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[day - 1][0];
    }
};