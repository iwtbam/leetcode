class Solution {
    public boolean canPartition(int[] nums) {
        int total = 0;
        for(int i = 0; i < nums.length; i++)
            total += nums[i];
        if(total % 2 == 1)
            return false;
        int half = total / 2;
        boolean[] dp = new boolean[half + 1];
        dp[0] = true;
     
        for(int num : nums){
            for(int i = half; i >= num; i--){
                if(dp[i])
                    continue;
                dp[i] = dp[i] || dp[i - num];
            }
        }
        
        return dp[half];
    }
}