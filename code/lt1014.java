import java.util.*;

class Solution {
    public int maxScoreSightseeingPair(int[] A) {
        int left = A[0];
        int len = A.length;
        int sum = 0;
        
        for(int i = 1; i < len; i++){
            sum = Math.max(sum, left + A[i] - i);
            left = Math.max(left, A[i] + i);
        }

        return sum;
    }
}