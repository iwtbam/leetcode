import java.util.*;

class Solution {
    public String findContestMatch(int n) {
        List<String> res = new ArrayList<>();
        for(int i = 0; i < n; i++){
             res.add(String.valueOf(i+1));
        }
        
        while(res.size() > 1){
         
            List<String> temp = new ArrayList<>();
            int size = res.size();
            for(int i = 0, j = size - 1; i < j; i++, j--){
                temp.add("(" + res.get(i) + "," + res.get(j) +")");
            }
            
            res = temp;
        }
        
        return res.get(0);
    }
}