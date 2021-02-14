// https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/
// number of longest increasing subsequence
class Solution {
    public int findNumberOfLIS(int[] nums) {
        int L = nums.length;

        if(L == 0)
            return 0;

        int[] dp = new int[L];
        int[] count = new int[L];
        
        Arrays.fill(dp, 1);
        Arrays.fill(count, 1);

        int maxL = 1;
        for(int i = 1; i < L; i++){
            for(int j = i - 1; j >= 0; j--)
                if(nums[i] > nums[j]){
                    if(dp[j] + 1 == dp[i])
                        count[i] += count[j];
                    
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                }

            maxL = Math.max(dp[i], maxL);
        }

        // System.out.println(maxL);

        // for(int i = 0; i < L; i++)
        //     System.out.print(dp[i] + " ");
        // System.out.println();
        // for(int i = 0; i < L; i++)
        //     System.out.print(count[i] + " ");
        // System.out.println();

        int c = 0;
        for(int i = 0; i < L; i++){
            c += maxL == dp[i] ? count[i] : 0;
        }

        return c;
    }
}