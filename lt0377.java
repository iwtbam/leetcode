// https://leetcode-cn.com/problems/combination-sum-iv/
// combination sum iv
class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] dp = new int[target+1];
        dp[0] = 1;
//         for(int i = 0; i < nums.length; i++){
//             for(int v = nums[i]; v <= target; v++){
//                 dp[v] += dp[v - nums[i]];
//             }
//         }
        
        for(int i = 1; i <= target; i++){
            for(int num : nums){
                if(i >= num)
                    dp[i] += dp[i - num];
            }
        }
        
        return dp[target];
    }
    
    // public int helper(int[] nums, int target){
    //     for(int i = 0; )
    // }
}