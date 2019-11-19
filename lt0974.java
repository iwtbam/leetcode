class Solution {
    public int subarraysDivByK(int[] A, int K) {
        int len = A.length;
        if(len == 0)
            return 0;
        
        int[] sum = new int[len + 1];
        
        
        for(int i = 1; i <= len; i++){
            sum[i] = sum[i - 1] + A[i - 1];    
        }
        
        int[] count = new int[K];
        
        for(int s : sum){
            count[(s % K + K) % K]++;
        }
        
        int res = 0;
        
        for(int c : count)
            res += (c - 1) * c / 2;
        
        return res;
    }
}