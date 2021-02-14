
//2019-11-19:11-36 双指针不优
class Solution {
    public String shortestPalindrome(String s) {
        int len = s.length();
        if(len <= 1)
            return s;

        char[] chs = s.toCharArray();
        int maxLen = 0;
        for(int i = 1; i < len; i++){
            maxLen = Math.max(maxLen, helper(chs, i, i));
            maxLen = Math.max(maxLen, helper(chs, i - 1, i));
        }
        
        String prefix = new StringBuffer(s.substring(maxLen + 1)).reverse().toString();
        return prefix + s;
    }
    
    public int helper(char[] chs, int i, int j){
        
        while(i >= 0 && j < chs.length){
            if(chs[i] != chs[j])
                break;
            if(i == 0)
                return j;
            i--;
            j++;
        }
        return 0;
    }
}