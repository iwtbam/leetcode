import java.util.*;
class Solution {
        
        int[] dx = new int[]{0, 0, 1, -1};
        int[] dy = new int[]{1, -1, 0, 0};
        
        public int[][] updateMatrix(int[][] matrix) {
            int rows = matrix.length;
            if(rows == 0)
                return matrix;
            int cols = matrix[0].length;
            if(cols == 0)
                return matrix;
            
            Queue<int[]> q = new LinkedList<>();
            int[][] vis = new int[rows][cols];
            
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    if(matrix[i][j] == 0){
                        q.offer(new int[]{i, j});
                        vis[i][j] = 1;
                    }
                }
            }
            
            while(q.size() > 0){
                int[] top = q.poll();
                int x = top[0];
                int y = top[1];
                int dis = matrix[x][y];
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= 0 && nx < rows && ny>=0 && ny < cols && vis[nx][ny]==0 && matrix[nx][ny]!=0){
                        matrix[nx][ny] = dis + 1;
                        vis[nx][ny] = 1;
                        q.offer(new int[]{nx, ny});
                    }
                }
            }
            
            return matrix;
        }
    }