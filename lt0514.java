import java.util.*;

class Solution {
    public int findRotateSteps(String ring, String key) {
        Map<Character, ArrayList<Integer>> record = new HashMap<>();
        for(int i = 0; i < ring.length(); i++){
            char k = ring.charAt(i);
            if(!record.containsKey(k))
                record.put(k, new ArrayList<Integer>());
            record.get(k).add(i);
        }
        
        int rl = ring.length(), kl = key.length();
        int[][] dp = new int[rl][kl];
        
        for(int i = 0; i < rl; i++)
            Arrays.fill(dp[i], UN_SOLVE);
        
        List<Integer> indexs = record.get(key.charAt(0));
    
        for(int index : indexs){
            dp[index][0] = minDis(index, 0, rl);       
        }
        
        
        for(int i = 1; i < kl; i++){
            char c = key.charAt(i);
            char p = key.charAt(i-1);
            
            for(int i1 : record.get(c)){
                for(int i2 : record.get(p)){
                    dp[i1][i] = Math.min(dp[i1][i], dp[i2][i-1] + minDis(i1, i2, rl));
                }
            }
        }
        
        int res = UN_SOLVE;
        
        for(int i = 0; i < rl; i++)
            res = Math.min(res, dp[i][kl-1]);
        
        return res;
    }
    
    public int minDis(int in1, int in2, int len){
        int dis = Math.abs(in1 - in2);
        return Math.min(dis, len - dis) + 1;
    }
    
    private final int UN_SOLVE = Integer.MAX_VALUE / 2;
}