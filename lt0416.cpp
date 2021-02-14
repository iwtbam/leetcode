// https://leetcode-cn.com/problems/partition-equal-subset-sum/
// partition equal subset sum
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        size_t size = nums.size();
        long long sum = 0;
        for(int i = 0; i < size; i++){
            sum += nums[i];
        }

        if(sum % 2 == 1)
            return false;

        int half = sum / 2;

        vector<int> dp(half + 1, 0);
        dp[0] = 1;

        for(int i = 0; i < size; i++){
            for(int cap = half; cap >= nums[i]; cap--){
                if(dp[cap] == 1)
                    continue;
                dp[cap] = dp[cap - nums[i]];
            }
        }

        return dp[half];
    }
};