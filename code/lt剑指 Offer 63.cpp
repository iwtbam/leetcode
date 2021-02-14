// https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
// gu piao de zui da li run lcof
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size == 0)
            return 0;
        
        int buy = prices[0];
        int sell = 0;

        for(int i = 1; i < size; i++){
            sell = max(sell, prices[i] - buy);
            buy = min(buy, prices[i]);
        }
        
        return sell;
    }
};

// dp[i][1] = max(dp[i - 1][1], prices[i] - dp[i - 1][0])
// dp[i][0] = min(dp[i - 1][0], prices[i]);