import java.util.*;

class Solution {
    public String[] uncommonFromSentences(String A, String B) {
        String[] as = A.split(" ");
        String[] bs = B.split(" ");
        Map<String, Integer> am = new HashMap<>();
        Map<String, Integer> bm = new HashMap<>();
        Set<String> ts = new HashSet<>();
        for(String a : as){
            ts.add(a);
            am.put(a, am.getOrDefault(a, 0) + 1);
        }
        
        for(String b : bs){
            ts.add(b);
            bm.put(b, bm.getOrDefault(b, 0) + 1);
        }
        
        List<String> res = new ArrayList<>();
        for(String w : ts){
            if(am.getOrDefault(w, 0) + bm.getOrDefault(w, 0) == 1)
                res.add(w);
        }
        
        return res.toArray(new String[res.size()]);
    }
}