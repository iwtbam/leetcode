// https://leetcode-cn.com/problems/minimum-number-of-days-to-disconnect-island/
// minimum number of days to disconnect island
class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
      
        rows = grid.size();
        cols = grid[0].size();
        if(count(grid) != 1)
            return 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    if(count(grid) > 1)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }

    int count(vector<vector<int>>& grid){
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        int num = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(vis[i][j] == 0 && grid[i][j] == 1){
                    bfs(grid, vis, i, j);
                    num++;
                }
            }
        }
        return num;
    }

    void bfs(const vector<vector<int>>& grid, vector<vector<int>>& vis, int x, int y){
        queue<pair<int, int>> q;
        vis[x][y] = 1;
        q.emplace(x, y);
        while(q.size()){
            auto [cx, cy] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = cx + dxs[i];
                int ny = cy + dys[i];
                if(nx < 0 || nx >= rows || ny < 0 || ny >= cols || !grid[nx][ny] || vis[nx][ny])
                    continue;
                vis[nx][ny] = 1;
                q.emplace(nx, ny);
            }
        }
    }

private:
    int rows, cols;
    int dxs[4] = {0, 0, 1, -1};
    int dys[4] = {1, -1, 0, 0};
};