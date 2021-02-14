// https://leetcode-cn.com/problems/longest-turbulent-subarray/
// longest turbulent subarray
class Solution {
    public int maxTurbulenceSize(int[] A) {
        int count = 1;
        int maxCount = 1;
        int L = A.length;
        if(L == 1)
            return L;
        
        if(L == 2){
            return A[0] == A[1] ? 1 : 2;
        }
        
        int pre = (A[0] - A[1]);
        if(pre!=0)
            pre = pre / Math.abs(pre);
        
        boolean zero = true;
        for(int i = 1; i < L - 1; i++){
            int sign = A[i] - A[i + 1];
            if(sign!=0){
                sign = sign / Math.abs(sign);
                zero = false;
            }
            if(sign!=pre && sign!=0 && pre !=0){
                count++;
            }else{
                maxCount = Math.max(maxCount, count);
                count = 1;
            }
            pre = sign;
        }
        
        maxCount = Math.max(maxCount, count);
        
        return zero ? 1 :  maxCount + 1;
    }
}