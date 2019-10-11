class Solution {
    public int shortestWordDistance(String[] words, String word1, String word2) {
        int pos1 = -1, pos2 = -1, pre = -1, res = Integer.MAX_VALUE;
        for(int i = 0; i < words.length; i++){
            String str = words[i];
            pre = pos1;
            if(word1.equals(str))
                pos1 = i;
            
            if(word2.equals(str))
                pos2 = pos1 == i ? pre : i;
            
            
            if(pos1 != -1 && pos2 != -1)
                res = Math.min(res, Math.abs(pos2 - pos1));
        }
        
        return res;
    }
}