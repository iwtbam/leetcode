class Solution {
    public int kConcatenationMaxSum(int[] arr, int k) {
        long sum = 0;
        for(int i = 0; i < arr.length; i++)
            sum += arr[i];
        
        long sum1 = maxSum(arr, 1);
        if(k == 1)
            return (int)(sum1 % MOD);
        long sum2 = maxSum(arr, 2);
        if(k == 2)
            return (int)(Math.max(sum1, sum2) % MOD);

        return (int)(Math.max(sum1, Math.max(sum2, sum2 + (k - 2) * sum)) % MOD);
    }

    public int maxSum(int[] arr, int repeat){
        long sum = 0, maxSum = 0;
        int len = arr.length;
        for(int i = 0; i < repeat * len; i++){
            sum += arr[i % len];
            if(sum < 0)
                sum = 0;
            else
                maxSum = Math.max(maxSum, sum);
        }

        return (int)maxSum;
    }

    private final int MOD = (int)Math.pow(10, 9) + 7;
}