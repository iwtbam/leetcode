// https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
// ji qi ren de yun dong fan wei lcof
class Solution {
public:
    int dxs[4] = {0, 1};
    int dys[4] = {1, 0};


    int movingCount(int m, int n, int k) {
        vector<vector<int>> grid(m, vector<int>(n, 1));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                grid[i][j] = small_k(i, j, k);
            }
        }

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 0;
        int res = 1;

        while(q.size()){
            auto [cx, cy] = q.front();
            q.pop();
            for(int i = 0; i < 2; i++){
                int nx = cx + dxs[i];
                int ny = cy + dys[i];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == 0)
                    continue;
                res++;
                grid[nx][ny] = 0;
                q.push({nx, ny});
            }
        }      
        return res;
    }

    int small_k(int i, int j, int k){
        if(i / 10 + i % 10 + j / 10 + j % 10 <= k)
            return true;
        return false;
    }
};


