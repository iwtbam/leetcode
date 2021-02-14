import java.util.*;

class Solution {
    public boolean validWordSquare(List<String> words) {
    
        int n = words.size();
        for(int i = 0; i < n; i++){
            int m = words.get(i).length();
            for(int j = 0; j < m; j++){
                
                if(j > n -1 || i > words.get(j).length() -1)
                    return false;
                
                if(words.get(i).charAt(j) != words.get(j).charAt(i))
                    return false;
            }
        }
        
        return true;
    }
}