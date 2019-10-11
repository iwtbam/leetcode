class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int rows = matrix.length;
        if(rows == 0)
            return 0;
        int cols = matrix[0].length;
        if(cols == 0)
            return 0;
        
        int[][] sums = new int[rows][cols];
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int part1 = i - 1 >= 0 ? sums[i-1][j] : 0;
                int part2 = j - 1 >= 0 ? sums[i][j-1] : 0;
                int part3 = i - 1 >= 0 && j - 1 >=0 ? sums[i-1][j-1]:0;
                sums[i][j] = part1 + part2 - part3 + matrix[i][j];
            }
        }
        
        int res = Integer.MIN_VALUE;
        
        for(int lr = 0; lr < rows; lr++){
            for(int lc = 0; lc < cols; lc++){
                for(int rr = lr; rr < rows; rr++){
                    for(int rc = lc; rc < cols; rc++){
                        int part1 = lr - 1 >= 0 ? sums[lr - 1][rc] : 0;
                        int part2 = lc - 1 >= 0 ? sums[rr][lc - 1] : 0;
                        int part3 = lr - 1 >= 0 && lc - 1 >= 0 ? sums[lr - 1][lc - 1] : 0;
                        int region = sums[rr][rc] - part1 - part2 + part3;
                        
                        if(region == k)
                            return k;
                        
                        if( region < k && region > res)
                            res = region;
                    }
                }
            }
        }
        
        return res;
    }
}