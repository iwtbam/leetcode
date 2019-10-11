import java.util.*;

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int len = nums.length;
        int[] res = new int[len];
        Arrays.fill(res, 1);

        int left = 1, right = 1;
        for(int i = 0; i < len; i++){
            res[i] *= left;
            res[len - i - 1] *= right;
            left  *= nums[i];
            right *= nums[len - i - 1];
        }
        
        return res;
        
    }
}