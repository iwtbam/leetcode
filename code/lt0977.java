class Solution {
    public int[] sortedSquares(int[] A) {
        int len = A.length;
        int left = -1, right = len;
        for(int i = 0; i < len; i++){
            if(A[i] > 0){
                right = i;
                break;
            }
        }
        
        left = right - 1;
        int start = 0;
        int[] res = new int[len];
        while(left >= 0 && right < len){
            if(Math.abs(A[left]) >= Math.abs(A[right])){
                res[start++] = (int)Math.pow(A[right++], 2);
            }else{
                res[start++] = (int)Math.pow(A[left--], 2);
            }
        }
        
        while(left >= 0){
            res[start++] = (int)Math.pow(A[left--], 2);
        }
        
        while(right < len){
            res[start++] = (int)Math.pow(A[right++], 2);
        }
        
        return res;
    }
}