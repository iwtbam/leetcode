#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        int size = prices.size();
        for(int i = 0; i < size; i++)
        {
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, dp_i_0 - prices[i] - fee);
        }
        return dp_i_0;
    }
};