import java.util.*;

class Solution {
    public int threeSumSmaller(int[] nums, int target) {
        int sum = 0;
        Arrays.sort(nums);
        for(int i = 0; i < nums.length - 2; i++){
            sum += count(nums, i + 1, target - nums[i]);
        }
        return sum;
    }
    
    public int count(int[] nums, int start, int target){
        int left = start;
        int right= nums.length - 1;
        int sum = 0;
        while(left < right){
            if(nums[left] + nums[right] < target){
                sum += right - left;
                left++;
            }else{
                right--;
            }
        }
        
        return sum;
    }
}