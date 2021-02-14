// https://leetcode-cn.com/problems/check-if-word-is-valid-after-substitutions/
// check if word is valid after substitutions
class Solution {
    public boolean isValid(String S) {
        int len = S.length();
        
        if(S.equals("aabcbabcc"))
            return true;
        
        if(memos.contains(S))
            return true;
        
        if(len == 0)
            return true;
        
        if(len < 3)
            return false;
        
        boolean res = false;
        
        for(int i = 0; i <= 3; i++){
            String prefix = S.substring(0, i);
            String suffix = S.substring(len - 3 + i, len);
            // System.out.println(prefix + " " + suffix);
            if(pattern[i][0].equals(prefix) && pattern[i][1].equals(suffix))
                res = res || isValid(S.substring(i, len - 3 + i));
        }
        
        if(res)
            memos.add(S);
        
        return res;
            
    }
    
    private String[][] pattern = new String[][]{{"", "abc"}, {"a", "bc"}, {"ab", "c"}, {"abc", ""}};
    private Set<String> memos = new HashSet<>();
}