import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Collections;


class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums, Integer Collections) {
        int len = nums.length;
        ArrayList<Integer> res = new ArrayList<>();
        
        if(len == 1){
            res.add(nums[0]);
            return res;
        }
        Arrays.sort(nums);
        int[] dp = new int[len];
        Arrays.fill(dp, 1);
        int maxLen = 0;

        for(int i = 1; i < len; i++){
            for(int j = i - 1; j >= 0; j--){
                if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }

            maxLen = Math.max(maxLen, dp[i]);
        }

        for(int i = len - 1; i>=0;i--){
            if(dp[i] == maxLen){
                res.add(nums[i]);
                maxLen--;
            }
        }

        Collections.reverse(res);
        return res;   
    }
}