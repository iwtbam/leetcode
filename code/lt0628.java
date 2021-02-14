class Solution {
    public int maximumProduct(int[] nums) {
        int l1 = Integer.MIN_VALUE, l2 = Integer.MIN_VALUE, l3 = Integer.MIN_VALUE;
        int m1 = Integer.MAX_VALUE, m2 = Integer.MAX_VALUE;
        
        for(int i = 0; i < nums.length; i++){
            if(nums[i] >= l1){
                l3 = l2;
                l2 = l1;
                l1 = nums[i];
                continue;
            }
            
            if(nums[i] >= l2){
                l3 = l2;
                l2 = nums[i];
                continue;
            }
            
            if(nums[i] >= l3){
                l3 = nums[i];
            }
        }
        
        for(int i = 0; i < nums.length; i++){
            if(nums[i] < m2){
                m1 = m2;
                m2 = nums[i];
                continue;
            }
            
            if(nums[i] < m1)
                m1 = nums[i];
        }
        
        return Math.max(m1 * m2 * l1, l1 * l2 * l3);
    }
    
    
}