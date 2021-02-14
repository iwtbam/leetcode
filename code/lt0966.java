import java.util.*;

class Solution {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        
        sets.add('a');
        sets.add('o');
        sets.add('e');
        sets.add('u');
        sets.add('i');
        
        int wLen = wordlist.length, qLen = queries.length;
        Set<String> record1 = new HashSet<String>();        
        Map<String, String> record2 = new HashMap<String, String>();
        Map<String, String> record3 = new HashMap<String, String>();
        
        for(int i = 0; i < wLen; i++){
            String word = wordlist[i];
            String lower = word.toLowerCase();
            record1.add(word);
            if(!record2.containsKey(lower))
                record2.put(lower, word);
            String dealed = deal(lower);
            if(!record3.containsKey(dealed))
                record3.put(dealed, word);
        }
        
        String[] res = new String[qLen];
        
        Arrays.fill(res, "");
        
        for(int i = 0; i < qLen; i++){
            String q = queries[i];
            if(record1.contains(q)){
                res[i] = q;
                continue;
            }
            
            String lower = q.toLowerCase();
            if(record2.containsKey(lower)){
                res[i] = record2.get(lower);
                continue;
            }
            
            String dealed = deal(lower);
            
            if(record3.containsKey(dealed)){
                res[i] = record3.get(dealed);
                continue;
            }
            
        }
        
        return res;
        
    }
    
    public String deal(String s){
        StringBuffer sb = new StringBuffer();
        for(int i = 0; i < s.length(); i++){
            if(sets.contains(s.charAt(i)))
                sb.append('*');
            else
                sb.append(s.charAt(i));
        }
        
        return sb.toString();
    }
    
    private Set<Character> sets = new HashSet<>();
}