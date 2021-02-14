#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j]=='1')
                {
                    num++;
                    helper(grid, i, j);
                }
            }
        }
        
        return num;
    }
    
    void helper(vector<vector<char>>& grid, int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        int rows = grid.size();
        int cols = grid[0].size();
        grid[i][j] = '0';
        while(q.size())
        {
            auto [curx, cury] = q.front();
            q.pop();
           
            for(int i = 0; i < 4; i++)
            {
                int nx = curx + dx[i];
                int ny = cury + dy[i];
                if(nx >= 0 && ny >= 0 && nx < rows  && ny < cols && grid[nx][ny]=='1')
                {
                    q.push({nx, ny});
                    grid[nx][ny] = '0';
                }
                    
            }
            
        }
    }
};