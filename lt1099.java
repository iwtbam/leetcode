import java.util.*;

class Solution {
    public int twoSumLessThanK(int[] A, int K) {
        Arrays.sort(A);
        int left = 0, right = A.length - 1;
        int res = -2000;
        while(left < right){
            if(A[left] + A[right] < K){
                res = K - (A[left] + A[right]) < K - res ? A[left] + A[right] : res;
                left++;
            }
            else
                right--;
        }
        
        return res == -2000 ? -1 : res;
    }
}