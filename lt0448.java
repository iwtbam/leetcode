import java.util.*;

class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int i = 0, len = nums.length;       
        List<Integer> res = new ArrayList<>();
        if(len == 0)
            return res;
        
        while(i < len){
            if(nums[i] == i + 1 || nums[nums[i] - 1] == nums[i]){
                i++;
                continue;
            }
            swap(nums, i, nums[i] - 1);
        }
        
        for(i = 0; i < len; i++){
            if(nums[i] != i + 1)
                res.add(i + 1);
        }
        
        return res;
    }
    
    public void swap(int[] nums, int i1, int i2){
        nums[i1] = nums[i1] ^ nums[i2];
        nums[i2] = nums[i1] ^ nums[i2];
        nums[i1] = nums[i1] ^ nums[i2];
    }
}