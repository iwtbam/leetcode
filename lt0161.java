// https://leetcode-cn.com/problems/one-edit-distance/
// one edit distance
class Solution {
    public boolean isOneEditDistance(String s, String t) {
        char[] sArr = s.toCharArray();
        char[] tArr = t.toCharArray();
        int sL = sArr.length;
        int tL = tArr.length;

        if(Math.abs(tL - sL) > 1 )
            return false;
        int n = 0, tn = Math.abs(tL - sL);
        for(int i = 0, j = 0 ; i < sL && j < tL; i++, j++){
            if(sArr[i] != tArr[j]){
                if(sL < tL)
                    i--;
                
                if(sL > tL)
                    j--;
                n++;
            }

            if(n > 1)
                return false;
        }

        return Math.max(n, tn) == 1;
    }
}