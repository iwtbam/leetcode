import java.util.*;

class Solution {
    public int largestPerimeter(int[] A) {
        Arrays.sort(A);
        int len = A.length;
        // int res = 0;
        for(int i = len - 3; i >= 0; i--){
            if(A[i] + A[i+1] > A[i+2])
                return A[i] + A[i+1] + A[i+2];
        } 
        return 0;
    }
}