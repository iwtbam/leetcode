import java.util.*;

class Solution {
    public int findSubstringInWraproundString(String p) {
        
        int len = p.length();
        
        if(len <= 1)
            return len;
        
        int[] dp = new int[26];
        int count = 1;
        dp[p.charAt(0) - 'a'] = 1;
        for(int i = 1; i < len; i++){   
            if(p.charAt(i) == p.charAt(i-1) + 1 || (p.charAt(i-1) == 'z' && p.charAt(i) == 'a'))
                count++;
            else
                count = 1;
            int index = p.charAt(i) - 'a';
            dp[index] = Math.max(dp[index], count);
        }
        int sum = 0;
        for(int n : dp)
            sum += n;
        return sum;
    }
}