// https://leetcode-cn.com/problems/count-servers-that-communicate/
// count servers that communicate
class Solution {
    public int countServers(int[][] grid) {
        rows = grid.length;
        cols = grid[0].length;
        int total = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 0)
                    continue;
                int count = bfs(grid, i, j);
                if(count <= 1)
                    continue;
                total += count;
            }
        }
        
        return total;
    }
    
    public int bfs(int[][] grid, int x, int y){
        Queue<int[]> q  = new LinkedList<>();
        grid[x][y] = 0;
        int count = 1;
        q.offer(new int[]{x, y});
        while(q.size() > 0){
            int[] top = q.poll();
            int cx = top[0];
            int cy = top[1];
            
            for(int i = 0; i < rows; i++){
                if(grid[i][cy] == 0)
                    continue;
                grid[i][cy] = 0;
                count++;
                q.offer(new int[]{i, cy});
            }
            
            for(int i = 0; i < cols; i++){
                if(grid[cx][i] == 0)
                    continue;
                grid[cx][i] = 0;
                count++;
                q.offer(new int[]{cx, i});
            }
        }
        
        return count;
    }
    
    private int rows;
    private int cols;
}