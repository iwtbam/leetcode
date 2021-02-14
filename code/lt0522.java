import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int findLUSlength(String[] strs) {
        Arrays.sort(strs, new Comparator<String>() {
            public int compare(String o1, String o2) {
                Integer len1 = o1.length();
                Integer len2 = o2.length();
                return len2.compareTo(len1);
            }
        });
        
        for(int i = 0; i < strs.length; i++){
            boolean isres = true;
            for(int j = 0; j < strs.length && strs[j].length() >= strs[i].length(); j++){
                
                if(i == j)
                    continue;
                
                if(isSubstring(strs[j], strs[i])){
                    isres = false;
                    break;
                }
            }
          
            if(isres)
                return strs[i].length();
        }
        
        return -1;
    }
    
    public boolean isSubstring(String s1, String s2){
        int p1 = 0, p2 = 0;
     
        while(p1 < s1.length() && p2  < s2.length()){
            if(s1.charAt(p1) == s2.charAt(p2)){
                p1++;
                p2++;
            }else{
                p1++;
            }
        }
        
        return p2 == s2.length();
    }
}

