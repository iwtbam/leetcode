import java.util.*;

class Solution {
    int[] dxs = new int[]{0, 0, 1, -1};
    int[] dys = new int[]{1, -1, 0, 0};
    
    public int maxDistance(int[][] grid) {
        int n = grid.length;
        int[][] dis = new int[n][n];
        
        for(int i = 0; i < n; i++)
            Arrays.fill(dis[i], INIT_DIS);
        
        Queue<int[]> q = new LinkedList<>();
        
        for(int i = 0; i < n; i++){
            for(int j  = 0; j < n;j++){
                if(grid[i][j] == 1){
                    // System.out.println(i + " " + j);
                    // bfs(grid, dis, i, j);
                    // break;
                    dis[i][j] = 0;
                    q.offer(new int[]{i, j});
                }
            }
        }
        
        
        bfs(grid, dis, q);

        int maxDis = -INIT_DIS;
        
        for(int i = 0; i < n; i++){
            for(int j = 0;j < n; j++){
               // System.out.print(dis[i][j] + " ");
                maxDis = Math.max(maxDis, dis[i][j]);
            }
            // System.out.println();
        }
        
        if(maxDis == 0 || maxDis == INIT_DIS)
            return -1;
        
        return maxDis;
    }
    
    public void bfs(int[][] grid, int[][] dis, Queue<int[]> q){
        int n = dis.length;
        boolean[][] vis = new boolean[n][n];
      
        while(q.size() != 0){
            int[] top = q.poll();
            vis[top[0]][top[1]] = true;
            int nd = dis[top[0]][top[1]] + 1;
            for(int i = 0; i < 4; i++){
                int nx = top[0] + dxs[i];
                int ny = top[1] + dys[i];
                if(nx >= 0 && nx < n && ny >=0 && ny < n && !vis[nx][ny] && grid[nx][ny] == 0 ){
                    dis[nx][ny] = Math.min(dis[nx][ny], nd);
                    q.offer(new int[]{nx, ny});
                }
            }
        }
    }
    
    private final int INIT_DIS = Integer.MAX_VALUE / 2;
}