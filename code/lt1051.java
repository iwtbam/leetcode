// https://leetcode-cn.com/problems/height-checker/
// height checker
class Solution {
    public int heightChecker(int[] heights) {
        
        int len = heights.length;
        int[] temp = new int[len];
        System.arraycopy(heights, 0, temp, 0, len);
        Arrays.sort(temp);
        int count = 0;
        for(int i = 0; i < len; i++){
            if(temp[i]!=heights[i])
                count++;
        }
        
        return count;
    }
}