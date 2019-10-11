import java.util.*;


class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        Set<String> words = new HashSet<String>();
        for(String word : wordDict)
            words.add(word);
       
        return wordBreak(s, 0, words);
    }
    
    public List<String> wordBreak(String s, int start, Set<String> words){
 
        if(memo.get(start)!=null)
            return memo.get(start);
        
        List<String> res = new ArrayList<String>();
        
        if(start >= s.length()){
            res.add(new String());
        }
        
        
        for(int end = start + 1; end <= s.length(); end++){
            String word = s.substring(start, end);
            if(!words.contains(word))
                continue;
            List<String> suffixs = wordBreak(s, end, words);
            for(String suffix:suffixs){
                String nword = word;
                if(!suffix.equals(new String()))
                    nword = nword + " " + suffix;
                res.add(nword);
            }
           
        }
        
        memo.put(start, res);
        
        return res;
    }
    
    private Map<Integer, List<String>> memo = new HashMap<>();
    private List<String> res = new ArrayList<>();
}