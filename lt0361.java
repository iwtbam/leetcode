class Solution {
    
    int[] dx = new int[]{0, 0, -1, 1};
    int[] dy = new int[]{1, -1, 0, 0};
    
    public int maxKilledEnemies(char[][] grid) {
        int rows = grid.length;
        if(rows == 0)
            return 0;
        int cols = grid[0].length;
        if(cols == 0)
            return 0;
        
        int maxKill = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] != '0')
                    continue;
                int count = 0;
                for(int d = 0; d < 4; d++){
                    int len = 1;
                    while(len > 0){
                        
                        int ni = i + dx[d] * len;
                        int nj = j + dy[d] * len;

                        if(ni >=0 && ni < rows && nj >=0 && nj < cols && grid[ni][nj]!='W'){
                           if(grid[ni][nj]=='E'){
                                count++;
                           }
                        }
                        else
                            break;
                        len++;
                    }
                }
                maxKill = Math.max(maxKill, count);
            }
        }
        return maxKill;
    }
}