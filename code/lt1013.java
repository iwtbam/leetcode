// https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum/
// partition array into three parts with equal sum
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int total = 0;
        int len = A.length;
        for(int i = 0; i < len; i++)
            total += A[i];
        
        if(total % 3 != 0)
            return false;
        
        int sub = 0, count = 0;
        for(int i = 0; i < len; i++){
            sub += A[i];
            if(sub == total / 3){
                sub = 0;
                count++;
                if(count == 2 && i < len - 1){
                    return true;
                }
            }
        }
        
        return false;
    }
}