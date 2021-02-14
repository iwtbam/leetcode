// https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets/
// partition to k equal sum subsets
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
       int sum = Arrays.stream(nums).sum();
       if(sum % k != 0)
            return false;
        int target = sum  / k;
        int L = nums.length;
        Arrays.sort(nums);
        if(nums[L - 1] > target)
            return false;

        int[] dp = new int[1 << L];
        boolean[] res = new boolean[1 << L];
        res[0] = true;
        for(int state = 0; state < 1 << L; state++){
            if(!res[state])
                continue;

            for(int i = 0; i < L; i++){
                int next = state | 1 << i;
                if(next == state)
                    continue;
                if(nums[i] > target - dp[state] % target)
                    break;
                res[next] = true;
                dp[next] = dp[state] + nums[i];
            }
        }

        return res[(1 << L) - 1];
    }
}