#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        size_t size = cost.size();
        vector<int> dp(size+1, 0);
        
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= size; i++)
        {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]); 
        }
        
        return dp[size];
    }
};