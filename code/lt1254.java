// https://leetcode-cn.com/problems/number-of-closed-islands/
// number of closed islands
class Solution {
    public int closedIsland(int[][] grid) {
        rows = grid.length;
        cols = grid[0].length;
        int count = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1)
                    continue;
                count += bfs(grid, i, j);
            }
        }
        
        return count;
        
    }
    
    int bfs(int[][] grid, int x, int y){
        grid[x][y] = 1;
        int res = 1;
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{x, y});
        while(q.size() > 0){
            int[] cur = q.poll();
            for(int i = 0; i < 4; i++){
                int nx = cur[0] + dxs[i];
                int ny = cur[1] + dys[i];
                if(nx < 0 || nx >= rows || ny < 0 || ny >= cols){
                    res = 0;
                    continue;
                }
                
                if(grid[nx][ny] == 0){
                    grid[nx][ny] = 1;
                    q.offer(new int[]{nx, ny});
                }
            }
        }
        
        return res;
    }
    
    int rows = 0;
    int cols = 0;
    int[] dxs = {0, 0, 1, -1};
    int[] dys = {1, -1, 0, 0};
    
}