import java.util.*;

class Solution {
    public List<String> generateSentences(List<List<String>> synonyms, String text) {
        String[] words = text.split(" ");
        Map<String, String> dict = new HashMap<>();
        for(List<String> synonym : synonyms){
            dict.put(synonym.get(0), synonym.get(1));
            dict.put(synonym.get(1), synonym.get(0));
        }
        Set<String> res = new TreeSet<>();
        helper(words, dict, res, 0);
        System.out.println(res.size());
        return new ArrayList<String>(res);
    }
    
    public void helper(String[] words, Map<String, String> dict, Set<String> res, int step){
        int size= words.length;
        if(step == size){
            StringBuffer sb = new StringBuffer();
            for(int i = 0; i < size; i++){
                sb.append(words[i]);
                if(i != size - 1)
                    sb.append(" ");
            }
            res.add(sb.toString());
            return;
        }
        
        
        String word = words[step];
        helper(words, dict, res, step + 1);
        Set<String> record = new HashSet<>();
        if(dict.containsKey(word)){
            word = dict.get(word);
            while(!record.contains(word)){
                record.add(word);
                String[] temp = new String[size];
                System.arraycopy(words, 0, temp, 0, size);
                temp[step] = word;
                helper(temp, dict, res, step + 1);
                if(dict.containsKey(word))
                    word = dict.get(word);
            }
        }
        
    }
}