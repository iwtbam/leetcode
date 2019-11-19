class Solution {
    
    int[] dxs = new int[]{0,  0, 1, -1};
    int[] dys = new int[]{1, -1, 0,  0};
    
    public int getMaximumGold(int[][] grid) {
        int maxGold = 0;
        int rows = grid.length;
        if(rows == 0)
            return 0;
        int cols = grid[0].length;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] != 0){
                    maxGold = Math.max(maxGold, helper1(grid, i, j, 0));
                    // helper2(grid, i, j);
                }
            }
        }
        
        return maxGold;
    }
    
    public int helper1(int[][] grid, int x, int y, int gold){
        int rows = grid.length;
        int cols = grid[0].length;
        if(x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] == 0)
            return gold;
        
        int maxGold = 0;
        for(int i = 0;  i < 4; i++){
            int curGold = grid[x][y];
            grid[x][y] = 0;
            maxGold = Math.max(maxGold, helper1(grid, x + dxs[i], y + dys[i], gold + curGold));
            grid[x][y] = curGold;
        }
        
        return maxGold;
    }
}