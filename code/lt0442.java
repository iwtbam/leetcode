import java.util.*;

//2019-10-20:17-23
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        int i = 0, len = nums.length;
        while(i < len){
            if(nums[i] == i + 1 || nums[nums[i] - 1] == nums[i]){
                i = i + 1;
                continue;
            }
            swap(nums, i, nums[i] - 1);   
        }
        
        List<Integer> res = new ArrayList<>();
        
        for(i = 0; i < len; i++){
            if(nums[i] != i + 1)
                res.add(nums[i]);
        }
        
        return res;
    }
    
    public void swap(int[] nums, int i1, int i2){
        nums[i1] = nums[i1] ^ nums[i2];
        nums[i2] = nums[i1] ^ nums[i2];
        nums[i1] = nums[i1] ^ nums[i2];
    }
}

// 2019-10-20:16-54 空间复杂度不符合要求 
// class Solution {
//     public List<Integer> findDuplicates(int[] nums) {
//         Set<Integer> record = new HashSet<Integer>();
//         List<Integer> res = new ArrayList<>();
        
//         for(int num : nums){
//             if(record.contains(num))
//                 res.add(num);
//             else
//                 record.add(num);
//         }
        
//         return res;
//     }
// }