// 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int len2 = grid.size();
        int len1 = len2 ? grid[0].size() : 0;

        if(!(len1 && len2))
            return 0;

        for(int i = 1; i < len2; i++)
            grid[i][0] += grid[i-1][0];
        
        for(int i = 1; i < len1; i++)
            grid[0][i] += grid[0][i-1];

        for(int i = 1; i < grid.size(); i++)
        {
            for(int j = 1; j < grid.size(); j++)
            {
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }

        return grid[len2-1][len1-1];        
    }
};

int main()
{
    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    Solution s;
    int r = s.minPathSum(grid);

    cout << r<< endl;
    return 0;
}