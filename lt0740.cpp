#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int size = nums.size();
        int mval = 0;
        for(int i = 0; i < size; i++)
            mval = max(mval, nums[i]);


        vector<int> dp(mval+1, 0);

        
        for(int i = 0; i < size; i++){
            dp[nums[i]] += nums[i];
        }
    

        for(int i = 2; i <=mval; i++)
            dp[i] = max(dp[i-1], dp[i-2] + dp[i]);

        return dp[mval]; 
    }
};