class Solution {
    
    private final int[] dxs = {0, 0, 1, -1};
    private final int[] dys = {1,-1, 0,  0};
    
    public int uniquePathsIII(int[][] grid) {
        int rows = grid.length;
        if(rows == 0)
            return 0;
        int cols = grid[0].length;
        if(cols == 0)
            return 0;
        
        int total = 0;
        int sx = 0, sy = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] != -1)
                    total++;
                if(grid[i][j] == 1){
                    sx = i;
                    sy = j;
                }
            }
        }
        
        boolean[][] vis = new boolean[rows][cols];
        return helper(grid, vis, sx, sy, 0, total);
    }
    
    public int helper(int[][] grid,  boolean[][] vis, int x, int y, int cur, int total){
        if(cur >= total)
            return 0;
        
        int rows = grid.length;
        int cols = grid[0].length;
        
        if(x < 0 || y < 0 || x >= rows || y>=cols || vis[x][y] || grid[x][y]==-1)
            return 0;
        
        if(grid[x][y] == 2){
            return cur == total - 1 ? 1 : 0;
        }
        
        vis[x][y] = true;
        
        int sum = 0;
        for(int i = 0; i < 4; i++)
            sum += helper(grid, vis, x + dxs[i], y + dys[i], cur + 1, total);
        
        vis[x][y] = false;
        return sum;
    }
}