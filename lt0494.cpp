#include <vector>
#include <numeric>
using namespace std;

#if defined(S1)
//2019-06-16:09-37 回溯超时

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return helper(nums, S, 0, 0);
    }
    
    int  helper(vector<int>& nums, int S, int step, int total){
        
        if(step == nums.size() && total == S){
            return 1;
        }
        
        if(step >= nums.size())
            return 0;
        
        int count = 0;
        

        count += helper(nums, S, step + 1, total + nums[step]) 
               + helper(nums, S, step + 1, total - nums[step]);

        
        return count;
        
    }
};

#else

//2019-06-16:09-37 dp

class Solution{
public:
    int findTargetSumWays(vector<int>& nums, int s)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int a = sum * 2 + 1;
        if(s >= a || s + sum >= a)
            return 0;

        vector<int> dp(a, 0);

        dp[0] = 1;

        for(auto& i:nums)
            i = 2 * i;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = a-1; j >=nums[i]; j--)
                dp[j] += dp[j - nums[i]];
        }

        return dp[sum + s];
    }
};

#endif