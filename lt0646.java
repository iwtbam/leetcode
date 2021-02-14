// https://leetcode-cn.com/problems/maximum-length-of-pair-chain/
// maximum length of pair chain
class Solution {
    public int findLongestChain(int[][] pairs) {
        int len = pairs.length;
        int[] dp = new int[len];
        
        Arrays.sort(pairs, new Comparator<int[]>(){
           public int compare(int[] p1, int[] p2){
               return p1[1] - p2[1] == 0 ? p1[0] - p2[0] : p1[1] - p2[1];
           }
        });
        
        int maxLen = 1;
        int end = pairs[0][1];
        for(int i = 1; i < len; i++){
            if(pairs[i][0] > end){
                maxLen++;
                end = pairs[i][1];
            }
        }
        return maxLen;
    }
}