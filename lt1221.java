import java.util.*;

class Solution {
    public int balancedStringSplit(String s) {
        Stack<Character> cs = new Stack<Character>();
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(cs.size() == 0 || c == cs.peek()){
                cs.push(c);
                continue;
            }
            
            if(c != cs.peek())
                cs.pop();
            
            if(cs.size() == 0)
                count++;
        }
        
        return count;
    }
}