import java.util.*;

class Solution {
    public boolean areSentencesSimilar(String[] words1, String[] words2, List<List<String>> pairs) {
        if(words1.length != words2.length)
            return false;
        
        Map<String,Set<String>> related = new HashMap<>();
        for(List<String> pair : pairs){
            String key = pair.get(0);
            if(!related.containsKey(key))
                related.put(key, new HashSet<String>());
            related.get(key).add(pair.get(1));
        }
        
        int len = words1.length;
        
        for(int i = 0; i < len; i++){
            if(words1[i].equals(words2[i]))
                continue;
            
            if(related.containsKey(words1[i]) && related.get(words1[i]).contains(words2[i]))
                continue;
            
            if(related.containsKey(words2[i]) && related.get(words2[i]).contains(words1[i]))
                continue;
            
            
            return false;
        }
        
        return true;
        
    }
}