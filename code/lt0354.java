import java.util.*;

class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        int len = envelopes.length;
        
        if(len <= 0)
            return 0;
        
        Arrays.sort(envelopes, new Comparator<int[]>(){
           public int compare(int[] a, int[] b){
               if(a[0] == b[0])
                   return a[1] - b[1];
               return a[0] - b[0];
           } 
        });
        
       
        int[] dp = new int[len];
        
        dp[0] = 1;
        int res = 1;
        for(int i = 1; i < len; i++){
            int maxval = 0;
            for(int j = i; j >= 0; j--){
                if(envelopes[j][1] < envelopes[i][1] && envelopes[j][0] < envelopes[i][0])
                    maxval = Math.max(maxval, dp[j]);
            }
            
            dp[i] = maxval + 1;
            res = Math.max(res, dp[i]);
        }
        
        return res;
    }
}