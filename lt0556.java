import java.util.*;

class Solution {
    public int nextGreaterElement(int n) {
        char[] s = String.valueOf(n).toCharArray();
        int len = s.length;
        int i = len - 1;
        
        for(; i >= 1;i--){
            if(s[i - 1] < s[i])
                break;
        }
        
        if(i == 0)
            return -1;
        
        int min = i;
        
        for(int j = i; j < len; j++){
            if(s[j] > s[i - 1] && s[j] < s[min])
                min = j;
        }
        
        char temp = s[i-1];
        s[i-1] = s[min];
        s[min] = temp;
        
        Arrays.sort(s, i, len);
        
        Long res = Long.parseLong(String.valueOf(s));
        if(res > Integer.MAX_VALUE)
            return -1;
        return res.intValue();
    }
}