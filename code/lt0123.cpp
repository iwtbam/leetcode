#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        int max_k = (size + 1) / 2;
        return k >= max_k ? max_profit_inf(prices): max_profit_k(k, prices);
    }
    
    int max_profit_inf(vector<int>& prices){
        int delta = 0;
        int size = prices.size();
        int max_profit = 0;
        for(int i = 0; i < size - 1; i++)
        {
            delta = prices[i+1] - prices[i];
            if(delta > 0)
                max_profit += delta;
        }
        
        return max_profit;
    }
    
    int max_profit_k(int k, vector<int>& prices){
        int size = prices.size();
        vector<vector<vector<int>>> dp = {size + 1, vector<vector<int>>(k+1, vector<int>(2, 0))};
        for(int i = 0; i <= k; i++){
            dp[0][i][0] = 0;
            dp[0][i][1] = INT_MIN;
        }
        
        for(int i = 0; i <= size; i++)        
            dp[i][0][1] = INT_MIN;
        
       
        
        for(int i = 1; i <= size; i++){
            for(int j = k; j >= 1;j--){
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i-1]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i-1]);
            }
        }
        return dp[size][k][0];
    }
};