class Solution {
    public int maxNumberOfApples(int[] arr) {
        int len = arr.length;
        
        if(len == 0)
            return 0;
        
        int[] dp = new int[5001];
        for(int i = 0; i < len; i++){
            for(int w = 5000; w >= arr[i]; w--){
                dp[w] = Math.max(dp[w], dp[w-arr[i]] + 1);
            }
        }
        
        int res = 0;
        
        for(int i = 0; i < 5001; i++)
            res = Math.max(res, dp[i]);
        
        return res;
    }
}