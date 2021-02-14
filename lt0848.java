// https://leetcode-cn.com/problems/shifting-letters/
// shifting letters
class Solution {
    public String shiftingLetters(String S, int[] shifts) {
        
        if(shifts.length == 0)
            return S;
        
        for(int i =  shifts.length - 2; i >= 0; i--)
            shifts[i] = (shifts[i + 1] + shifts[i]) % 26;
        
        StringBuffer sb = new StringBuffer();
        for(int i = 0; i < shifts.length; i++){
            sb.append((char)((S.charAt(i) - 'a' + shifts[i]) % 26 + 'a'));
        }
        
        return sb.toString();
    }
}