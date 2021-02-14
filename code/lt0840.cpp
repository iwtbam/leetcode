// https://leetcode-cn.com/problems/magic-squares-in-grid/
// magic squares in grid
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0)
            return 0;
        int cols = grid[0].size();
        if(cols == 0)
            return 0;

        int num = 0;
        for(int i = 0; i <= rows - 3; i++){
            for(int j = 0; j <= cols - 3; j++){
                if(check(grid, i, j))
                    num++;
                
            }
        }
        return num;
    }

    bool check(vector<vector<int>>& grid, int x ,int y){
        vector<int> nums(10, 0);
        for(int i = x; i < x + 3; i++){
            int sum = 0;
            for(int j = y; j < y + 3; j++){
                if(grid[i][j] >= 10)
                    return false;
                if(++nums[grid[i][j]] > 1)
                    return false;
                sum += grid[i][j];
            }
            if(sum != 15)
                return false;
        }

        for(int j = y; j < y + 3; j++){
            int sum = 0;
            for(int i = x; i < x + 3; i++){
                sum += grid[i][j];
            }
            if(sum != 15)
                return false;
        }

        if(grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2] != 15)
            return false;
        
        if(grid[x + 2][y] + grid[x + 1][y + 1] + grid[x][y + 2] != 15)
            return false;
        
        return true;
    }
};