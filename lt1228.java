class Solution {
    public int missingNumber(int[] arr) {
        int len = arr.length;
        int d = (arr[len - 1] - arr[0]) / len;
        
        int start = arr[0];
        for(int i = 1; i < len; i++){
            if(arr[0] + i * d != arr[i])
                return arr[0] + i * d;
        }
        
        return 0;
    }
}