#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.empty())
            return 0;
        
        vector<int> dp = {nums.begin(), nums.end()};

        int size = dp.size();

        if(size == 1)
            return dp[0];

        if(size == 2)
            return max(dp[0], dp[1]);
        
        dp[1] = max(dp[0], dp[1]);
            
        for(int i = 2; i < size; i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + dp[i]);
        }

        return dp[size - 1];
    }
};