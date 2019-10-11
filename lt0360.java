class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        double axis = - (b * 1.0) / (a * 2.0);
        int len = nums.length;
        int left = -1, right = len;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] > axis){
                right = i;
                break;
            }
        }
        
        int[] res = new int[len];
        left = right - 1;
        int start = 0;
        while(left >= 0 && right < len){
            
            if(Math.abs(nums[right] - axis) >= Math.abs(nums[left] - axis)){
                res[start++] = f(a, b, c, nums[left]);
                left--;
            }else{
                res[start++] = f(a, b, c, nums[right]);
                right++;
            }
            
        }
        
        while(left >= 0){
            res[start++] = f(a, b, c, nums[left--]);
        }
        
        while(right < len){
            res[start++] = f(a, b, c, nums[right++]);
        }
        
        if(a < 0){
            left = 0;
            right = len - 1;
            while(left < right){
                res[right] = res[left] ^ res[right];
                res[left] =  res[left] ^ res[right];
                res[right] = res[left] ^ res[right];
                left++;
                right--;
            }
        }
        
        return res;
    }
    
    public int f(int a, int b, int c, int x){
        return a * x * x + b * x + c;
    }
}