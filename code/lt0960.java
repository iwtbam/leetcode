class Solution {
    public int minDeletionSize(String[] A) {
        if(A.length <= 0)
            return 0;
        int L = A[0].length();
        int[] dp = new int[L];
        dp[0] = 1;
        int maxPre = 1;
        for(int i = 1; i < L; i++){
            dp[i] = 1;
            for(int j = i - 1; j >= 0; j--){
                boolean greater = true;
                for(String item : A){
                    if(item.charAt(i) < item.charAt(j)){
                        greater = false;
                        break;
                    }
                }

                if(greater)
                    dp[i] = Math.max(dp[i], dp[j] + 1);
            }
            maxPre = Math.max(maxPre, dp[i]);
        }

        return L - maxPre;
    }
}