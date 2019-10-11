#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        size_t size = coins.size();
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(i - coins[j] >= 0 && dp[i-coins[j]]!=-1)
                    dp[i] = dp[i] == -1 ? dp[i-coins[j]] + 1:min(dp[i-coins[j]] + 1, dp[i]);
            }
        }

        return dp[amount];
    }
};