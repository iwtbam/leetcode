// https://leetcode-cn.com/problems/binary-prefix-divisible-by-5/
// binary prefix divisible by 5
class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
        int res = 0;
        List<Boolean> rval = new ArrayList<>();
        for(int i = 0; i < A.length; i++){
            res = (res << 1 | A[i]) % 5;
            if(res == 0)
                rval.add(true);
            else
                rval.add(false);
        }
        
        return rval;
    }
}