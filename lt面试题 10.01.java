// https://leetcode-cn.com/problems/sorted-merge-lcci/
// sorted merge lcci
class Solution {
    public void merge(int[] A, int m, int[] B, int n) {
        int lenA = A.length;
        int lenB = B.length;
        int len = lenA + lenB;
        int p = lenA - 1, pA = lenA - lenB - 1, pB = lenB - 1;
        
        while(pA >= 0 && pB >= 0){
            if(A[pA] > B[pB]){
                A[p] = A[pA];
                pA--;
            }else{
                A[p] = B[pB];
                pB--;
            }
            p--;
        }

        while(pA >= 0){
            A[p] = A[pA];
            p--;
            pA--;
        }

        while(pB >= 0){
            A[p] = B[pB];
            p--;
            pB--;
        }

        return ;
    }
}