// https://leetcode-cn.com/problems/number-of-enclaves/
// number of enclaves
class Solution {
    
    int[] dxs = new int[]{0, 0, 1, -1};
    int[] dys = new int[]{1, -1, 0, 0};
    
    public int numEnclaves(int[][] A) {
        int rows = A.length;
        if(rows == 0)
            return 0;
        int cols = A[0].length;
        int res = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(A[i][j] == 1)
                    res +=  bfs(A, i, j);
            }
        }
        
        return res;
    }
    
    public int bfs(int[][] A, int x, int y){
        int rows = A.length;
        int cols = A[0].length;
        Queue<int[]> q = new LinkedList<>();
        int count = 1;
        boolean flag = false;
        q.offer(new int[]{x, y});
        A[x][y] = 0;
        while(q.size() > 0){
            int[] top = q.poll();
            for(int i = 0;  i< 4; i++){
                int nx = top[0] + dxs[i];
                int ny = top[1] + dys[i];
                if(nx < 0 || nx >=rows || ny < 0|| ny >=cols){
                    flag = true;
                    continue;
                }
                
                if(A[nx][ny] == 1){
                    A[nx][ny] = 0;
                    q.offer(new int[]{nx, ny});
                    count++;
                }
            }
        }
        
        return flag ? 0 : count;
    }
    

}