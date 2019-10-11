import java.util.*;
//2019-09-21:21-48 dp 还是不好理解

class Solution {
    public int splitArray(int[] nums, int m) {
        int len = nums.length;
        
        int[][] memos = new int[len + 1][len + 1];
        
        for(int i = 0; i <= len; i++)
            Arrays.fill(memos[i], Integer.MAX_VALUE);
        
        
        int[] sum = new int[len + 1];
        
        for(int i = 0; i < len; i++)
            sum[i + 1] = sum[i] + nums[i];
        
        memos[0][0] = 0;
        for(int i = 1; i <= len; i++){
            for(int j = 1; j <= m; j++){
                for(int k = 0; k < i; k++){
                    memos[i][j] = Math.min(memos[i][j], Math.max(memos[k][j - 1], sum[i] - sum[k]));
                }
            }
        }
        
        
        return memos[len][m];
    }
    
}


// 回溯 + 记忆化 
// class Solution {
//     public int splitArray(int[] nums, int m) {
//         int len = nums.length;
        
//         memos = new int[m + 1][len];
        
//         for(int i = 0; i <= m; i++)
//             Arrays.fill(memos[i], -1);
        
//         return splitArray(nums, m, 0);
//     }
    
//     public int splitArray(int[] nums, int m, int cur){
        
        
//         if(memos[m][cur] != -1)
//             return memos[m][cur];
        
//         int res = 0;
//         if(m == 1){
//             for(int i = cur; i < nums.length; i++)
//                 res =  res + nums[i];
//             memos[m][cur] = res;
//             return memos[m][cur] = res;
//         }
        
//         int sum = 0;
//         res = Integer.MAX_VALUE;
        
//         for(int i = cur; i <= nums.length - m; i++){
//             sum += nums[i];
//             res = Math.min(res, Math.max(sum, splitArray(nums, m - 1, i + 1)));
//         }
        
//         memos[m][cur] = res;
        
//         return memos[m][cur];
//     }
    
//     private int[][] memos = null;
// }