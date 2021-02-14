// https://leetcode-cn.com/problems/zero-matrix-lcci/
// zero matrix lcci
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> rmark(rows, 0);
        vector<int> cmark(cols, 0);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    rmark[i] = 1;
                    cmark[j] = 1;
                }
            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(rmark[i] || cmark[j])
                    matrix[i][j] = 0;
            }
        }
    }
};