class Solution {
    public boolean detectCapitalUse(String word) {
        int len = word.length();
        
        if(len <= 1)
            return true; 
        
        int state = isLower(word.charAt(0)) ? 0 : 1;
        
        if(state == 1)
            state = isLower(word.charAt(1)) ? 0 : 1;
        
        if(state == 0 && !isLower(word.charAt(1)))
            return false;
            
        
        
        for(int i = 2; i < len; i++){
            char c = word.charAt(i);
            if(c >= 'a' && c <= 'z'){
                if(state ==1){
                    state = 2;
                    break;
                }
            }else{
                if(state == 0){
                    state = 2;
                    break;
                }
            }
        }
        
        return state < 2;
    }
    
    public boolean isLower(char c){
        return c >='a' && c <='z';
    }
}