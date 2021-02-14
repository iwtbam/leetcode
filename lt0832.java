// https://leetcode-cn.com/problems/flipping-an-image/
// flipping an image
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int rows = A.length;
        int cols = A[0].length;
        
        int[][] res = new int[rows][cols];
        
        for(int i = 0; i < rows; i++){
            for(int j = 0 ; j  < cols; j++){
                res[i][j] = A[i][cols - j - 1] == 1 ? 0 : 1;
            }
        }
        
        return res;
    }
}