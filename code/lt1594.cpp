// https://leetcode-cn.com/problems/maximum-non-negative-product-in-a-matrix/
// maximum non negative product in a matrix
class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<long long>> mx(rows, vector<long long>(cols, 1));
        vector<vector<long long>> mi(rows, vector<long long>(cols, 1));
        
        const int mod = 1e9 + 7;
        
        mx[0][0] = grid[0][0];
        mi[0][0] = grid[0][0];
        
        for(int i = 1; i < rows; i++){
            mx[i][0] = max(mx[i - 1][0], mi[i - 1][0]) * grid[i][0];
            mi[i][0] = min(mx[i - 1][0], mi[i - 1][0]) * grid[i][0];
            if(grid[i][0] < 0)
                swap(mx[i][0], mi[i][0]);
        }
        
        
        for(int i = 1; i < cols; i++){
            mx[0][i] = max(mx[0][i - 1], mi[0][i - 1]) * grid[0][i];
            mi[0][i] = min(mx[0][i - 1], mi[0][i - 1]) * grid[0][i];
            if(grid[0][i] < 0)
                swap(mx[0][i], mi[0][i]);
        }
        
        
        for(int i = 1; i <  rows; i++){
            for(int j = 1; j < cols; j++){
                
                mx[i][j] = max(mx[i - 1][j], mx[i][j - 1]) * grid[i][j];
                mi[i][j] = min(mi[i - 1][j], mi[i][j - 1]) * grid[i][j];
                
                if(grid[i][j] < 0)
                    swap(mx[i][j], mi[i][j]);
                
            }
        }
        
        if(mx[rows - 1][cols - 1] >= 0)
            return mx[rows - 1][cols - 1] % mod;
        
        return -1;
    }
};