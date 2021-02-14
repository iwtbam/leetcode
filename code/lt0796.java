class Solution {
    public boolean rotateString(String A, String B) {
        
        if(A.length() != B.length())
            return false;
        
        int len = A.length();
        
        if(len == 0)
            return true;
        
        for(int i = 0; i < len; i++){
            boolean flag = true;
            for(int j = 0; j < len; j++){
                if(A.charAt((i + j)% len) != B.charAt(j)){
                    flag = false;
                    break;
                }
            }
            
            if(flag)
                return true;
        }
        
        return false;
    }
}