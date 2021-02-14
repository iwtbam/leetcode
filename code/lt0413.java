class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        int len = A.length;
        int dp = 0, sum = 0;
        for(int i = 1; i < len - 1; i++){
            if(A[i] - A[i-1] == A[i+1] - A[i]){              
                dp = 1 + dp;
                sum += dp;
            }else{
                dp = 0;
            }
        }       
        return sum;
    }
}