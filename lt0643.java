class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double avg = 0.0;
        int len = nums.length;
        
        for(int i = 0; i < k; i++)
            avg += nums[i];
        avg = avg / k;
        double res = avg;
        for(int i = k; i < len; i++){
            avg = (avg * k - nums[i - k] + nums[i]) / k;
            res = Math.max(res, avg);
        }
        
        return res;
    }
}