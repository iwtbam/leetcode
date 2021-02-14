// https://leetcode-cn.com/problems/find-common-characters/
// find common characters
class Solution {
    public List<String> commonChars(String[] A) {
        int[] hash = new int[26];
        Arrays.fill(hash, UN_INIT);
        for(String a : A){
            int len = a.length();
            int[] ahash = new int[26];
            for(int i = 0; i < len; i++)
                ahash[a.charAt(i) - 'a']++;
            for(int i = 0; i < 26; i++)
                hash[i] = Math.min(hash[i], ahash[i]);
        }
        
        List<String> res = new ArrayList<>();
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < hash[i]; j++){
                res.add(String.valueOf((char)('a' + i)));
            }
        }
        
        return res;
    }
    
    private final int UN_INIT = Integer.MAX_VALUE;
}