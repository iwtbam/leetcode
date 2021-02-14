// https://leetcode-cn.com/problems/previous-permutation-with-one-swap/
// previous permutation with one swap
class Solution {
    public int[] prevPermOpt1(int[] A) {
        int len = A.length, i = len - 2;
        for(; i >= 0; i--){
            if(A[i] > A[i + 1])
                break;
        }
        
        System.out.println(i);
        
        if(i == -1)
            return A;
        
        int maxJ = i + 1;
        for(int j = i + 2; j < len; j++){
            if(A[j] > A[maxJ] && A[j] < A[i])
                maxJ = j;
        }
        
        A[i] = A[maxJ] ^ A[i];
        A[maxJ] = A[maxJ] ^ A[i];
        A[i] = A[maxJ] ^ A[i];
        
        return A;
            
    }
}