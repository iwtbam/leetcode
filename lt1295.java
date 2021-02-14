// https://leetcode-cn.com/problems/find-numbers-with-even-number-of-digits/
// find numbers with even number of digits
class Solution {
    public int findNumbers(int[] nums) {
        int count = 0;
        for(int num:nums){
            count += check(num);
        }
        
        return count;
    }
    
    public int check(int num){
        
        if(num == 0)
            return 0;
        
        int bit = 0;
        
        while(num > 0)
        {
            num /= 10;
            bit++;
        }
        
        return bit % 2 == 0 ? 1 : 0;
    }
}