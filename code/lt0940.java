import java.util.*;


class Solution {
    public int distinctSubseqII(String S) {
        int len = S.length();
        int[] dp = new int[len];
        int sum = 1;
        Arrays.fill(dp, 1);
        dp[0] = 1;
        for(int i = 1; i < len; i++){
            char cur = S.charAt(i);
            for(int j = i - 1; j >= 0; j--){
                char pre = S.charAt(j);
                dp[i] = (dp[i] + dp[j]) % MOD;
                if(pre == cur){
                    dp[i] = dp[i] - 1;
                    break;
                }
            }
            
            sum = (sum + dp[i]) % MOD;
        }
        
        return sum;
    }
    
    private final int MOD = (int)Math.pow(10, 9) + 7;
}