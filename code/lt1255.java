// https://leetcode-cn.com/problems/maximum-score-words-formed-by-letters/
// maximum score words formed by letters
class Solution {
    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        int[] count = new int[26];
        for(int i = 0; i < letters.length; i++)
            count[letters[i] - 'a']++;
        int res = dfs(words, count, score, 0);
        return res;
    }
    
    public int dfs(String[] words, int[] count, int[] scores, int step){
        
        if(step == words.length)
            return 0;
        
        int res = 0;
        
        for(int i = step; i < words.length; i++){
            char[] chs = words[i].toCharArray();
            boolean flag = true;
            int[] temp = new int[26];
            
            for(int j = 0; j < chs.length; j++){
                temp[chs[j] - 'a']++;
            }            
            
            for(int j = 0; j < 26; j++){
                if(temp[j] > count[j]){
                    flag = false;
                    break;
                }
            }
            
            
            // System.out.println(words[i]);
            
            if(!flag)
                continue;
            
            int cur = 0;
            for(int j = 0; j < chs.length; j++){    
                count[chs[j] - 'a']--;
                cur += scores[chs[j] - 'a'];
            }
            
            
            res = Math.max(res, cur + dfs(words, count, scores, i + 1));
            
            for(int j = 0; j < chs.length; j++){
                count[chs[j] - 'a']++;
            }
        }
        
        
        return res;
        
    }
    
    
}