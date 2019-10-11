import java.util.*;

class WordDistance {

    public WordDistance(String[] words) {
        int len = words.length;
        starts = new HashMap<String, List<Integer>>();
        
        for(int i = 0; i < len; i++){
            String key = words[i];
            if(!starts.containsKey(key))
                starts.put(key, new ArrayList<Integer>());
            starts.get(key).add(i);
        }
    }
    
    public int shortest(String word1, String word2) {
        
        List<Integer> locs1 = starts.get(word1);
        List<Integer> locs2 = starts.get(word2);
        int loc1 = 0, loc2 = 0, res = Integer.MAX_VALUE;
        
        // System.out.println()
        
        while(loc1 < locs1.size() && loc2 < locs2.size())
        {
            res = Math.min(res, Math.abs(locs1.get(loc1) - locs2.get(loc2)));
            if(locs1.get(loc1) < locs2.get(loc2))
                loc1++;
            else
                loc2++;
        }
        
        return res;
    }
    
    private Map<String, List<Integer>> starts = null;
   
}