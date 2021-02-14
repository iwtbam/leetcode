// https://leetcode-cn.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
// minimum cost to make at least one valid path in a grid
class Solution {
public:
    
    int dxs[5] = {0, 0, 0, 1, -1};
    int dys[5] = {0, 1, -1, 0, 0}; 
    
    int minCost(vector<vector<int>>& grid) {
        this->grid = grid;
        rows = grid.size();
        if(rows == 0)
            return 0;
        cols = grid[0].size();
        vis.resize(rows, vector<vector<int>>(cols, vector<int>(5, 0)));        
        queue<vector<int>> q;
        q.push({0, 0, grid[0][0]});
        int cost = 0;
        while(q.size())
        {
            size_t size = q.size();
            for(int i = 0; i < size; i++)
            {
                vector<int>& cur = q.front();
                if(expand(q, cur[0], cur[1], cur[2]))
                    return cost;
                q.pop();
            }
            cost++;
        }

        return rows + cols - 2;
    }

    inline bool check(int x, int y)
    {
        if(x < 0 || x >= rows || y < 0 || y >= cols)
            return false;
        return true;
    }

    bool expand(queue<vector<int>>& cq, int x, int y, int d)
    {
        queue<pair<int, int>> q;
        q.emplace(x, y);
        int od = grid[x][y];
        grid[x][y] = d;
        vis[x][y][d] = 1;
        while(q.size())
        {
            auto [cx, cy] = q.front();
            q.pop();
            for(int i = 1; i <= 4; i++){
                if(vis[cx][cy][i])
                    continue;
                cq.push({cx, cy, i});
            }

            int nx = cx + dxs[grid[cx][cy]];
            int ny = cy + dys[grid[cx][cy]];
            if(!check(nx, ny))
                continue;


            if(vis[nx][ny][grid[nx][ny]])
                continue;

            if(nx == rows - 1 && ny == cols - 1)
                return true;
            q.emplace(nx, ny);
            vis[nx][ny][grid[nx][ny]] = 1;
          
        }
        grid[x][y] = od;
        return false;
    }

private:
    vector<vector<int>> grid;
    vector<vector<vector<int>>> vis;
    int rows, cols;
};