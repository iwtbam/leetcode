class Solution {
    public boolean checkPossibility(int[] nums) {
        int len = nums.length;
        if(len < 3)
            return true;
        int count = 0;
        if(nums[0] > nums[1]){
            nums[0] = nums[1];
            count++;
        }
        
        for(int i = 1; i < len - 1; i++){
            int right = nums[i + 1];
            if(nums[i] > right){
                count++;
                if(count > 1)
                    return false;
                
                int left = nums[i - 1];
                if(left > right)
                    nums[i+1] = nums[i];
                else
                    nums[i] = left;
            }
        }
        
        return true;
    }
}