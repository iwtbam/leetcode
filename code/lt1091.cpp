#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:

    int dx[8] = {0, 0, 1, 1, 1, -1, -1,-1};
    int dy[8] = {1,-1, 0,-1, 1,  0, -1, 1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.empty())
            return -1;
        
        if(grid[0][0])
            return -1;

        int row = grid.size();
        int col = grid[0].size();
        
        if(row == 1 && col == 1)
            return 1;

        vector<vector<int>> dis = {row,vector<int>(col, 0)};

        queue<pair<int, int>> pos;
        pos.push({0, 0});

        while(pos.size())
        {
            auto cur_pos = pos.front();
            pos.pop();
            for(int i = 0; i < 8 ;i++)
            {
                pair<int, int> next_pos = {cur_pos.first + dx[i], cur_pos.second + dy[i]};
                int x = next_pos.first;
                int y = next_pos.second;

                if( x >=0 && x < row && y >= 0 && y < col && !grid[x][y] && !dis[x][y] )
                {
                    dis[x][y] = dis[cur_pos.first][cur_pos.second] + 1;
                    pos.push(next_pos);
                }
            }
        }

        if(dis[row-1][col-1])
            return dis[row-1][col-1] + 1;
        return -1;
    }
};