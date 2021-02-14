import java.util.*;


class Solution {
    public int minCut(String s) {
        int len = s.length();
        if(len == 0)
            return 0;
        
        int[] dp = new int[len];
        Arrays.fill(dp, len - 1);
        
        for(int i = 0; i < len; i++){
            minCut(s, i, i, dp);
            minCut(s, i, i+1, dp);
        }
        
        return dp[len - 1];
    }
    
    public void minCut(String s, int i, int j, int[] dp){
        int len = s.length();
        while(i>=0 && j < len &&s.charAt(i)==s.charAt(j)){
            dp[j] = Math.min(dp[j], (i == 0 ? -1 : dp[i-1]) + 1);
            i--;
            j++;
        }
    }
  
   
}

// class Solution {
//     public int minCut(String s) {
//         int len = s.length();
//         int[][] dp =  new int[len + 1][len + 1];
//         for(int i = 0; i < len; i++){
//             dp[i][i] = 1;
//         }
        
//         for(int i = 0; i < len - 1; i++){
//             if(s.charAt(i) == s.charAt(i+1))
//                 dp[i][i+1] = 1;
//         }
        
//         for(int l = 1; l <= len - 2;l++){
//             for(int i = 0; i + l + 1 < len; i++){
                
//                 if(dp[i+1][i+l]==1 && s.charAt(i)==s.charAt(i+l+1))
//                     dp[i][i+l+1] = 1;
//             }
//         }
        
//         return minCut(0, s, dp);
//     }
    
//     public int minCut(int start, String s, int[][] dp){
//         if(dp[start][s.length() - 1] == 1)
//             return 0;
        
//         if(memo.get(start)!=null)
//             return memo.get(start);
        
//         int min = Integer.MAX_VALUE;
//         for(int i = start; i < s.length(); i++){
//             if(dp[start][i]==0)
//                 continue;
            
//             min = Math.min(min, 1 + minCut(i+1, s, dp));
//         }
        
//         memo.put(start, min);
        
//         return min;
//     }
    
//     private Map<Integer, Integer> memo = new HashMap<>();
// }