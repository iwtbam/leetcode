// https://leetcode-cn.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
// subtract the product and sum of digits of an integer
class Solution {
    public int subtractProductAndSum(int n) {
        
        if(n == 0)
            return 0;
        
        int mul_res = 1;
        int sum_res = 0;
        while(n!=0){
            int bit = n % 10;
            mul_res *= bit;
            sum_res += bit;
            n /= 10;
        }
        
        return mul_res - sum_res;
    }
}