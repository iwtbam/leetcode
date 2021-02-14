import java.util.*;

class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> res = new HashSet<>();
        for(String email : emails){
            String[] items = email.split("@");
            StringBuffer prefix = new StringBuffer();
            for(int i = 0; i < items[0].length(); i++){
                char c = items[0].charAt(i);
                if(c == '+')
                    break;
                
                if(c == '.')
                    continue;
                
                prefix.append(c);
            }
            
            res.add(prefix.toString() + "@" + items[1]);
        }
        
        return res.size();
    }
}