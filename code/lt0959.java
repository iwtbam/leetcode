import java.util.*;

class Solution {
    public int regionsBySlashes(String[] grid) {
        int N = grid.length;
        int[][] graph = new int[N * 3][N * 3];
        
        for(int i = 0; i < N; i++){
            char[] row = grid[i].toCharArray();
            for(int j = 0; j < N; j++){
                char c = row[j];
                if(c == '\\'){
                    graph[i * 3][j * 3] = 1;
                    graph[i * 3 + 1][j * 3 + 1] = 1;
                    graph[i * 3 + 2][j * 3 + 2] = 1;
                }           
                
                if(c == '/'){
                    graph[i * 3][j * 3 + 2] = 1;
                    graph[i * 3 + 1][j * 3 + 1] = 1;
                    graph[i * 3 + 2][j * 3] = 1;
                }
            }
        }
        
        int count = 0;
        for(int i = 0; i < N * 3; i++){
            for(int j = 0; j < N * 3; j++){
                if(graph[i][j] == 1)
                    continue;
                count++;
                bfs(graph, i, j, N * 3);
            }
        }
                   
        
        return count;
    }
    
    public void bfs(int[][] graph, int i, int j, int L){
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{i, j});
        graph[i][j] = 1;
        while(q.size() > 0){
            int[] top = q.poll();
            for(int d = 0; d < 4; d++){
                int nx = top[0] + dxs[d];
                int ny = top[1] + dys[d];
                if(nx >= 0 && nx < L && ny >= 0 && ny < L && graph[nx][ny]==0){
                    graph[nx][ny] = 1;
                    q.offer(new int[]{nx, ny});
                }
            }
        }
    }
    
    
    private final int[] dxs = new int[]{0, 0, 1, -1};
    private final int[] dys = new int[]{1, -1, 0, 0};
}