import java.util.*;

class Solution {
    public String[] reorderLogFiles(String[] logs) {
        List<String> logs1 = new ArrayList<>();
        List<String> logs2 = new ArrayList<>();
        
        for(String log : logs){
            char c = log.split(" ", 2)[1].charAt(0);
            if(isDigitl(c)){
                logs1.add(log);
            }else{
                logs2.add(log);
            }
        }
        
        Collections.sort(logs2, (log1, log2) -> {
            return compare(log1.split(" ", 2), log2.split(" ", 2));
        });
        
        int index = 0;
        
        for(int i = 0; i < logs2.size(); i++)
            logs[index++] = logs2.get(i);
        
        for(int i = 0; i < logs1.size(); i++)
            logs[index++] = logs1.get(i);
            
        return logs;
    }
    public boolean isDigitl(char c){
        return c >= '0' && c <= '9';
    }
    
    public int compare(String[] strs1, String[] strs2){
        if(strs1[1].compareTo(strs2[1])!=0)
            return strs1[1].compareTo(strs2[1]);
        return strs1[0].compareTo(strs2[0]);
    }
}