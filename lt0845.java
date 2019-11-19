class Solution {
    public int longestMountain(int[] A) {
        int L = A.length;
        
        if(L == 0)
            return 0;
        
        int[] left  = new int[L];
        int[] right = new int[L];
        
        left[0] = 0;
        right[L - 1] = 0;
        
        for(int i = 1; i < L; i++)
            left[i]  = A[i] > A[i - 1] ? left[i - 1] + 1 : 0;
        
        for(int i = L - 2; i >=0; i--)
            right[i] = A[i] > A[i + 1] ? right[i + 1] + 1 : 0; 
        
        int maxL = 0;
        
        for(int i = 0; i < L; i++)
            if(left[i]!= 0 && right[i]!=0)
                maxL = Math.max(maxL, left[i] + right[i] + 1);
        
        return maxL;
    }
}