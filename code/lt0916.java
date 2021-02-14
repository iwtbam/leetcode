import java.util.*;

class Solution {
    public List<String> wordSubsets(String[] A, String[] B) {
        int len = A.length;
        int[] sub = hashArray(B);
        List<String> res = new ArrayList<>();
        for(int i = 0; i < len; i++){
            int[] hash = hashStr(A[i]);
            if(subset(hash, sub))
                res.add(A[i]);
        }
        
        return res;
    }
    
    public int[] hashStr(String s){
        int[] code = new int[26];
        for(int i = 0; i < s.length(); i++)
            code[s.charAt(i) - 'a']++;
        return code;
    }
    public int[] hashArray(String[] strs){
        int[] code = new int[26];
        for(int i = 0; i < strs.length; i++){
            int[] temp = new int[26];
            for(int j = 0; j < strs[i].length(); j++)
                temp[strs[i].charAt(j) - 'a']++;
            for(int k = 0; k < 26; k++)
                code[k] = Math.max(code[k], temp[k]);
        }
        
        return code;
    }
    
    public boolean subset(int[] set, int[] sub){
      
        for(int j = 0; j < 26; j++)
            if(sub[j]!=0 && sub[j] > set[j])
                return false;

        return true;
    }
}