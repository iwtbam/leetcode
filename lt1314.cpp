// https://leetcode-cn.com/problems/matrix-block-sum/
// matrix block sum
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> sums = {rows, vector<int>(cols + 1, 0)};
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                sums[i][j + 1] = sums[i][j] + mat[i][j];
            }
        }
        
        vector<vector<int>> res = {rows, vector<int>(cols, 0)};
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int right  = min(j + K, cols - 1);
                int left   = max(j - K, 0);
                int bottom = max(i - K, 0);
                int up     = min(i + K, rows - 1);
                for(int k = bottom; k <= up; k++){
                    res[i][j] += sums[k][right + 1] - sums[k][left];   
                    // ;
                }
            }
        }
        
        return res;
    }
};