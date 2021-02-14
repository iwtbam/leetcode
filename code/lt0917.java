class Solution {
    public String reverseOnlyLetters(String S) {
        
        if(S.length() == 0)
            return S;
        
        char[] res = S.toCharArray();
        int len = S.length();
        int start = 0;
        for(int i = len - 1; i>=0; i--){
            
            while(start < len && !isChar(res[start]))
                start++;
            
            if(start >= len)
                return String.valueOf(res);
            
            if(!isChar(S.charAt(i)))
                continue;
            
            res[start] = S.charAt(i);            
            start++;
        }
        
        return String.valueOf(res);
    }
    
    public boolean isChar(char c){
        if(c >= 'a' && c <='z')
            return true;
        if(c >='A' && c <= 'Z')
            return true;
        return false;

        
    }
}