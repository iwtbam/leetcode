import java.util.*;

class Solution {
    public boolean isStrobogrammatic(String num) {
        
        record.put('0', '0');
        record.put('8', '8');
        record.put('6', '9');
        record.put('9', '6');
        record.put('1', '1');
        
        int s = 0, e = num.length() - 1;
        
        while(s < e){
            if(record.getOrDefault(num.charAt(s), '#') != num.charAt(e))
                return false;
            s++;
            e--;
        }
        
        if(s == e){
            char mid = num.charAt(s);
            if(mid == '0' || mid == '1' || mid == '8')
                return true;
            return false;
        }
        
        
        return true;
    }
       
    private Map<Character, Character> record =  new HashMap<>();
    
}