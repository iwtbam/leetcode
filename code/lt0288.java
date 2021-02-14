import java.util.*;

class ValidWordAbbr {

    public ValidWordAbbr(String[] dictionary) {
        
        for(String word : dictionary){
            if(record2.contains(word))
                continue;
            String wordAbbr = abbr(word);
            record.put(wordAbbr, record.getOrDefault(wordAbbr, 0) + 1);
            record2.add(word);
        }
    }
    
    public boolean isUnique(String word) {
        if(record2.contains(word))
            return record.get(abbr(word)) == 1;
        else
            return record.getOrDefault(abbr(word), 0) == 0;
    }
    
    public String abbr(String word){
        int len = word.length();
        if(len <= 2)
            return word;
        return word.charAt(0) + "" + (len - 2) + word.charAt(len - 1);
    }
    
    private Map<String, Integer> record = new HashMap<>();
    private Set<String> record2 = new HashSet<String>();
}
