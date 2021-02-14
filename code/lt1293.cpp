// https://leetcode-cn.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
// shortest path in a grid with obstacles elimination
struct State 
{
    int x;
    int y;
    int cost;
    State(int x = 0, int y = 0, int cost = 0):x(x), y(y), cost(cost){};
};

class Solution {
public:
    const int UNSOLVE = 0x3f3f3f3f;
    int dxs[4] = {0, 0, 1, -1};
    int dys[4] = {1, -1, 0, 0};
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        if(rows == 0)
            return 0;
        int cols = grid[0].size();
        vector<vector<vector<int>>> dis(rows, vector<vector<int>>(cols,vector<int>(k + 1, UNSOLVE)));

        dis[0][0][grid[0][0]] = 0;

        queue<State> q;
        q.emplace(0, 0, grid[0][0]);

        while(q.size())
        {
            auto [x, y, c] = q.front();
            q.pop();

            for(int d = 0; d < 4; d++){
                int nx = x + dxs[d];
                int ny = y + dys[d];
                if(nx < 0 || nx >= rows || ny < 0 || ny >= cols)
                    continue;
                int ncost = c + grid[nx][ny]; 
                if(ncost > k || dis[x][y][c] + 1 >= dis[nx][ny][ncost])
                    continue;
                dis[nx][ny][ncost] = dis[x][y][c] + 1;
                q.emplace(nx, ny, ncost);
            }
        }

        vector<int>& last = dis[rows - 1][cols - 1];
        int res = *min_element(last.begin(), last.end());
        return res == UNSOLVE ? -1 : res;
    }
};