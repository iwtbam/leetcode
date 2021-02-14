// https://leetcode-cn.com/problems/out-of-boundary-paths/
// out of boundary paths
class Solution {
    
    final int[] dxs = new int[]{0, 0, -1, 1};
    final int[] dys = new int[]{1, -1, 0, 0};
    
    public int findPaths(int m, int n, int N, int i, int j) {
        int[][][] dp = new int[2][m + 2][n + 2];
        dp[0][i + 1][j + 1] = 1;
        
        int count = 0;
        
        for(int step = 1; step <= N; step++){
            fill(dp[step & 1]);
            for(int x = 1; x < m + 1; x++){
                for(int y = 1; y < n + 1; y++){
                    for(int d = 0; d < 4; d++){
                        int nx = dxs[d] + x;
                        int ny = dys[d] + y;
                        
                        if(nx == 0 || ny == 0 || nx == m + 1 || ny == n+1)
                            count = (count + dp[(step-1) & 1][x][y]) % MOD;
                        
                        dp[step & 1][nx][ny] = (dp[step & 1][nx][ny] + dp[(step - 1) & 1][x][y]) % MOD;
                    }
                }
            }   
        }
        
        return count;
    }
    
    private void fill(int[][] arrays){
        for(int i = 0;  i < arrays.length; i++){
            Arrays.fill(arrays[i], 0);
        }
    }
    
    private final int MOD = (int)Math.pow(10, 9) + 7;
}