// https://leetcode-cn.com/problems/knight-probability-in-chessboard/
// knight probability in chessboard
class Solution {
    public double knightProbability(int N, int K, int r, int c) {
        double[][][] dp = new double[N][N][2];
        dp[r][c][0] = 1.0;
        double res = 0.0;
        for(int k = 1; k <= K; k++){
            for(int r1 = 0; r1 < N; r1++){
                for(int c1 = 0; c1 < N; c1++){
                    if(dp[r1][c1][k - 1 & 1] < ERR)
                        continue;
                    double p = dp[r1][c1][k-1 & 1] * 0.125;
                    for(int i = 0; i < 8; i++){
                        int nr = dxs[i] + r1;
                        int nc = dys[i] + c1;
                        if(nr >= 0 && nr < N && nc >= 0 && nc < N){
                            dp[nr][nc][k & 1] += p;
                        }else{
                            res+=p;
                        }
                    }
                }
            }
        }
        return 1.0 - res;
    }

    private final double ERR = Math.pow(0.1, 6);
    private int[] dxs = {1, 1, -1, -1, 2, 2, -2, -2};
    private int[] dys = {2, -2, 2, -2, 1, -1, 1, -1};

}