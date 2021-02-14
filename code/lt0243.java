class Solution {
    public int shortestDistance(String[] words, String word1, String word2) {
        int  len = words.length;
        int[] dis = new int[len];
        int pos1 = -1, pos2 = -1, res = Integer.MAX_VALUE;
        for(int i = 0; i < len; i++){
            
            if(word1.equals(words[i]))
                pos1 = i;
            if(word2.equals(words[i]))
                pos2 = i;
            
            if(pos1 != -1 && pos2!= -1)
                res = Math.min(res, Math.abs(pos2 - pos1));
            
        }
        
        return res;

    }
}