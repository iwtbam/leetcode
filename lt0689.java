// https://leetcode-cn.com/problems/maximum-sum-of-3-non-overlapping-subarrays/
// maximum sum of 3 non overlapping subarrays
class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int L = nums.length;
        
        int[] sums  = new int[L + 1];
        int[] left  = new int[L];
        int[] right = new int[L];


        for(int i = 1; i <= L; i++){
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        int maxRegion = 0;

        for(int i = k; i <= L - 2 * k; i++){
            if(maxRegion < sums[i] - sums[i - k]){
                maxRegion = sums[i] - sums[i - k];
                left[i] = i - k;
            }else{
                left[i] = left[i - 1];
            }
        }

        maxRegion = 0;

        for(int i = L - k; i >= 2 * k; i--){
            if(maxRegion <= sums[i + k] - sums[i]){
                maxRegion = sums[i + k] - sums[i];
                right[i] = i;
            }else{
                right[i] = right[i + 1];
            }
        }

        maxRegion = 0;
        int[] res = null;
        for(int i = k; i <= L - 2 * k; i++){
            int li = left[i];
            int ri = right[i + k];
            int temp = sums[li + k] - sums[li] + sums[i + k] - sums[i] + sums[ri + k] - sums[ri];
            if(temp > maxRegion){
                maxRegion = temp;
                res = new int[]{li, i, ri};
            }

        }

        return res;

    }
}