// https://leetcode-cn.com/problems/max-consecutive-ones-iii/
// max consecutive ones iii
class Solution {
    public int longestOnes(int[] A, int K) {
        int left = 0, right = 0, curK = 0, len = A.length, maxLen = 0, pre = 0;
        List<Integer> pos = new ArrayList<>();
        while(right < len){
            
            if(A[right] == 0){
                pos.add(right);
                curK++;
            }
            
            if(curK == K + 1){
                maxLen = Math.max(right - left, maxLen);
                left = pos.get(pre++) + 1;
                curK = K;
            }
            
            right++;
        }
        
        maxLen = Math.max(maxLen, right - left);
        
        return maxLen;
    }
}