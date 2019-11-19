import java.util.*;

class Solution {
    public String removeVowels(String S) {
        Set<Character> record = new HashSet<>();
        record.add('a');
        record.add('o');
        record.add('e');
        record.add('i');
        record.add('u');
        StringBuffer sb = new StringBuffer();
        for(int i = 0; i < S.length(); i++){
            char c = S.charAt(i);
            if(!record.contains(c))
                sb.append(c);
        }
        
        return sb.toString();
    }
}