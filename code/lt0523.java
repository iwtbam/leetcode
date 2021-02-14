import java.util.*;

class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int len = nums.length, sum = 0;
        Map<Integer, Integer> memos = new HashMap<>();
        memos.put(0, -1);
        for(int i = 0; i < len; i++){
            sum += nums[i];
            if(k != 0)
                sum = sum % k;
            if(memos.containsKey(sum)){
                if(i - memos.get(sum) > 1)
                    return true;
            }else{
                memos.put(sum, i);
            }
        }
        
        return false;
    }
}


// class Solution {
//     public boolean checkSubarraySum(int[] nums, int k) {
//         int len = nums.length;
//         for(int i = 0; i < len; i++){
//             int sum = 0;
//             for(int j = i; j < len; j++){
//                 sum += nums[j];
                
//                 if(j - i >= 1 && sum == k)
//                     return true;
                
//                 if(j - i >= 1 && k != 0 && sum % k == 0)
//                     return true;
//             }
//         }
        
//         return false;
//     }
// }