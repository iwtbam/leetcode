import java.util.*;

class Solution {
    public List<Integer> cheapestJump(int[] A, int B) {
        int N = A.length;
        List<Integer> res = new ArrayList<>();
        
        if(N == 0)
            return res;
        
        int[] dp = new int[N];
        int[] path = new int[N];
        
        Arrays.fill(dp, UN_SOLVED);
        
        dp[N - 1] = A[N - 1];
        path[N - 1] = N - 1;
        
        
        for(int i = N - 2; i >= 0; i--){
            if(A[i] == -1)
                continue;
            
            for(int j = 1; j <= B && i + j < N; j++){
                
                int cost = dp[i + j] + A[i];
                if(A[i + j] == -1 || dp[i] < cost)
                    continue;
                
                if(dp[i] > cost){
                    dp[i] = cost;
                    path[i] = i + j;
                }
            }
        }
      
        
        
        if(dp[0] == UN_SOLVED)
            return res;
        
        
        res.add(0, 1);
        int pos = 0;
        while(path[pos]!=pos){
            res.add(path[pos] + 1);
            pos = path[pos];
        }
        
        return res;
    }
    
    
    private final int UN_SOLVED = Integer.MAX_VALUE / 2;
}