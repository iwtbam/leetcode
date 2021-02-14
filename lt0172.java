// https://leetcode-cn.com/problems/factorial-trailing-zeroes/
// factorial trailing zeroes
class Solution {
    public int trailingZeroes(int n) {
        int count = 0;
        while(n / 5 != 0){
            count += n / 5;
            n = n / 5;
        }
        return count;
    }
}