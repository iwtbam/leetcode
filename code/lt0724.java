class Solution {
    public int pivotIndex(int[] nums) {
        int left = 0, right = 0;
        int n = nums.length;
        int[] res = new int[n];
        
        for(int i = 0; i < n; i++){
            res[i] += left;
            res[n - i - 1] -= right;
            left += nums[i];
            right += nums[n - i - 1];
        }
        
        for(int i = 0; i < n; i++)
            if(res[i] == 0)
                return i;
        return -1;
    }
}