// https://leetcode-cn.com/problems/sum-of-digits-in-the-minimum-number/
// sum of digits in the minimum number
class Solution {
    public int sumOfDigits(int[] A) {
        int min = A[0];
        for(int a : A)
            min = Math.min(a, min);
        int sum = 0;
        // System.out.println(min);
        while(min!=0){
            sum += (min) % 10;
            min = min / 10;
        }
        return sum % 2 == 0 ? 1 : 0;
    }
}