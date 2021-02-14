// https://leetcode-cn.com/problems/find-the-smallest-divisor-given-a-threshold/
// find the smallest divisor given a threshold
class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        int left = 1, right = Integer.MAX_VALUE - 1;
        int mid = 0;
        while(left <= right){
            mid = (left + right) / 2;
            if(calc(nums, mid, threshold)){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        
        while(mid > 0 && calc(nums, mid, threshold))
            mid--;
        
        while(!calc(nums, mid, threshold))
            mid++;
        
        
        return mid;
    }
    
    public boolean calc(int[] nums, int divide, int threshold){
        long sum = 0;
        for(int i = 0; i < nums.length; i++)
            sum  = sum + (int)Math.ceil(nums[i] * 1.0 / divide);
        return sum <= threshold;
    }
}