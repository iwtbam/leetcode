class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double err = 0.00001;
        double min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for(int num : nums){
            min = Math.min(min, num);
            max = Math.max(max, num);
        }
        
        while(max - min > err){
            double mid = (min + max) / 2;
            if(gt(nums, k, mid))
                min = mid;
            else
                max = mid;
        }
        
        return min;
        
    }
    
    public boolean gt(int[] nums, int k, double target){
        double sum = 0, min = 0, pre = 0;
        for(int i = 0; i < k; i++)
            sum += nums[i] - target;
        
        if(sum >= 0)
            return true;
        
        for(int i = k; i < nums.length; i++){
            sum += nums[i]   - target;
            pre += nums[i-k] - target;
            min = Math.min(pre, min);
            if(sum >= min)
                return true;
        }
        return false;
    }
}