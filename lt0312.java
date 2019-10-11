import java.util.*;

class Solution {
    public int maxCoins(int[] nums) {
     
        List<Integer> cons = new ArrayList<>();
        cons.add(1);
        for(int num : nums)
            cons.add(num);
        cons.add(1);

        int[][] dp = new int[cons.size()][cons.size()];

        for(int len = 2; len < cons.size(); len++){
            for(int i = 0; i < cons.size() - len; i++){
                int j = i + len;
                for(int k = i + 1; k < j; k++){
                    dp[i][j] = Math.max(dp[i][j], cons.get(i) * cons.get(k) * cons.get(j) + dp[i][k] + dp[k][j]);
                }
            }
        }

        return dp[0][cons.size()-1];
    }
}

// 回溯 + 记忆化 超时
// class Solution {
//     public int maxCoins(int[] nums) {
//         List<Integer> numsList = new LinkedList<>();
//         for(int num:nums)
//             numsList.add(num);
//         return maxCoins(numsList);
//     }
    
//     public int maxCoins(List<Integer> nums){
        
//         if(nums.size() == 0)
//             return 0;
        
//         if(memos.get(nums) != null)
//             return memos.get(nums);
        
//         int maxVal = Integer.MIN_VALUE;
//         for(int i = nums.size() - 1; i >= 0; i--){
//             int val = nums.get(i);
//             int left  = i >= 1 ? nums.get(i-1):1;
//             int right = i <= nums.size() - 2 ? nums.get(i+1) : 1; 
            
//             nums.remove(i);
//             maxVal = Math.max(maxVal, val * left * right + maxCoins(nums));
//             nums.add(i, val);
//         }
        
//         memos.put(nums, maxVal);
        
//         return maxVal;
//     }
    
//     private Map<List<Integer>, Integer> memos = new HashMap<>();
// }