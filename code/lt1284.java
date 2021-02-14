// https://leetcode-cn.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/
// minimum number of flips to convert binary matrix to zero matrix
class Solution {
    public int minFlips(int[][] mat) {
        m = mat.length;
        n = mat[0].length;


        this.mat = mat;        
        int res = -1;
        for(int i = 0; i < (1 << n); i++){
            flip = new int[m][n];
            int step = 0;
            for(int j = 0; j < n; j++){
                if((i & (1 << j))!=0){
                    flip[0][j] = 1;
                    step += 1;
                }
            }
            int num = calc();
            if(num >= 0 && (res < 0 || num + step < res)){
                res = num + step;
            }    
        }

        return res;
    }

    public int calc(){
        int step = 0;

        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(get(i - 1, j) == 1){
                    step++;
                    flip[i][j] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(get(m - 1, i) == 1)
                return -1;
        }

        return step;
    }

    public int get(int i, int j){
        int num = mat[i][j];
        for(int d = 0; d < 5; d++){
            int ni = i + dxs[d];
            int nj = j + dys[d];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n){
                num += flip[ni][nj];
            }
        }
        return num % 2;
    }

    private int[][] flip;
    private int[][] mat;
    private int m, n;
    private final int[] dxs = new int[]{0, 0, 0, 1, -1};
    private final int[] dys = new int[]{0, 1, -1, 0, 0};
}