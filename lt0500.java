import java.util.*;


class Solution {
    public String[] findWords(String[] words) {
        String[] lines = new String[]{
            "qwertyuiopQWERTYUIOP",
            "asdfghjklASDFGHJKL",
            "zxcvbnmZXCVBNM"
        };
        
        ArrayList<Set<Character>> sets = new ArrayList<>();
        
        for(int i = 0; i < 3; i++)
            sets.add(new HashSet<Character>());
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < lines[i].length(); j++)
                sets.get(i).add(lines[i].charAt(j));
        }
        
        List<String> res = new ArrayList<>();
        
        for(String word : words){
            for(int i = 0; i < 3; i++){
                int j = 0;
                for(; j < word.length(); j++)
                    if(!sets.get(i).contains(word.charAt(j)))
                        break;
                if(j == word.length()){
                    res.add(word);
                    break;
                }
            }
        }
        
        
        if(res.size()<1)
            return new String[0];
        return res.toArray(new String[1]);
        
    }
}