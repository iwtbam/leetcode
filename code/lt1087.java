import java.util.*;

class Solution {
    public String[] expand(String S) {
        List<String> res = expand(S, 0);
        Collections.sort(res);
        return res.toArray(new String[res.size()]);
    }
    
    public List<String> expand(String S, int index){
        

        List<String> res = new ArrayList<>();
        
        if(index >= S.length()){
            res.add("");
            return res;
        }
        
        List<String> prefixs = new ArrayList<>();
        int end = index;
        if(S.charAt(index)=='{'){
            for(end = index + 1; end < S.length(); end++){
                if(S.charAt(end)=='}')
                    break;
                if(S.charAt(end)==',')
                    continue;
                
                prefixs.add(String.valueOf(S.charAt(end)));
            }
            end++;
        }else{
            for(end = index; end < S.length(); end++){
                if(S.charAt(end)=='{')
                    break;
            }
            prefixs.add(S.substring(index, end));
        }
            
        List<String> suffixs = expand(S, end);
        
        for(int i = 0; i < prefixs.size(); i++){
            for(int j = 0; j < suffixs.size(); j++)
                res.add(prefixs.get(i) + suffixs.get(j));
        }
        
        return res;
        
    }
}