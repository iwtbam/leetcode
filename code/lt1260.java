import java.util.*;

class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int n = grid.length;
        int m = grid[0].length;
        int[] mGrid = new int[n];
        
        for(int i = 0; i < k; i++){
            for(int j = 0; j < n; j++)
                mGrid[j] = grid[j][m-1];
            
            for(int c = m -1; c >= 1; c--){
                for(int r = 0; r < n; r++){
                    grid[r][c] = grid[r][c -1];
                }
            }
            
            for(int r = 1; r < n; r++){
                grid[r][0] = mGrid[r - 1];
            }
            
            grid[0][0] = mGrid[n - 1];
        }
        
        List<List<Integer>> res = new ArrayList<>();
        for(int i = 0; i < n; i++){
            List<Integer> row = new ArrayList<Integer>(m);
            for(int j = 0; j < m; j++)
                row.add(grid[i][j]);
            res.add(row);
        }
        
        return res;
    }
}