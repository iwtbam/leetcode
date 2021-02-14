// https://leetcode-cn.com/problems/count-submatrices-with-all-ones/
// count submatrices with all ones
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        vector<vector<int>> sums(rows + 1, vector<int>(cols + 1, 0));
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                sums[i + 1][j + 1] = sums[i][j + 1] + sums[i + 1][j] - sums[i][j] + mat[i][j];
            }
        }
        
        int ans = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mat[i][j] == 0)
                    continue;
                for(int ii = i; ii < rows; ii++){
                    if(mat[ii][j] == 0)
                        break;
                    for(int jj = j; jj < cols; jj++){
                        int sum = sums[ii + 1][jj + 1] - sums[ii + 1][j] - sums[i][jj + 1] + sums[i][j];
                        if(sum == (ii - i + 1) * (jj - j + 1))
                            ans++;
                        else
                            break;
                        
                    }
                }
            }
        }
        
        return ans;
    }
};