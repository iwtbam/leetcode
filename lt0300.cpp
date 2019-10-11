#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        vector<int> dp(size, 0);
        dp[0] = 1;
        int maxans = 1;
        for(int i = 1; i < size; i++)
        {
            int maxval = 0;
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                    maxval = max(maxval, dp[j]);
            }

            dp[i] = maxval + 1;
            
            maxans = max(dp[i], maxans);
        }
        
        return maxans;
    }
};