// https://leetcode-cn.com/problems/path-with-minimum-effort/
// path with minimum effort
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        priority_queue<tuple<int, int, int>> q;
        
        vector<vector<int>> dp(rows, vector<int>(cols, INT_MAX));
        dp[0][0] = 0;
        
        q.emplace(0, 0, 0);
        
        while(q.size()){
            auto [v, x, y] = q.top();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = x + dxs[i];
                int ny = y + dys[i];
                if(nx < 0 || nx >= rows || ny < 0 || ny >= cols || max(-v, abs(heights[nx][ny] - heights[x][y])) >= dp[nx][ny])
                    continue;
                dp[nx][ny] = max(-v, abs(heights[nx][ny] - heights[x][y]));
                q.emplace(-dp[nx][ny], nx, ny);
            }
        }
        
        return dp[rows - 1][cols - 1];
    }
    
private:
    int dxs[4] = {0, 0, 1, -1};
    int dys[4] = {1, -1, 0, 0};
};