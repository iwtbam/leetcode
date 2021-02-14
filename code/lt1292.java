// https://leetcode-cn.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
// maximum side length of a square with sum less than or equal to threshold
class Solution {
    public int maxSideLength(int[][] mat, int threshold) {
        int rows = mat.length;
        int cols = mat[0].length;
        int[][] sum = new int[rows][cols + 1];
        
        for(int i = 0; i < rows; i++){
            for(int j = 1; j <= cols; j++){
                sum[i][j] = sum[i][j - 1] + mat[i][j - 1];
            }
        }
        
    
        
        int maxe = Math.min(rows, cols);
        int res = 0;
        
        for(int e = 1; e <= maxe; e++){
            
            for(int i = 0; i < cols - e + 1; i++){
                
                int j = i + e - 1;
                
                int total = 0;
                
                for(int k = 0; k < e; k++)
                    total += (sum[k][j + 1] - sum[k][i]);
                
                
                if(total < threshold){
                    res = e;
                    break;
                }
                
                for(int k = e; k < rows; k++){
                    total += ((sum[k][j + 1] - sum[k][i]) - (sum[k - e][j + 1] - sum[k - e][i]));
                    if(total <= threshold){
                        res = e;
                        break;
                    }
                }       
            }
        }
        
        return res;
    }
}