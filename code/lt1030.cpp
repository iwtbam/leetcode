// https://leetcode-cn.com/problems/matrix-cells-in-distance-order/
// matrix cells in distance order
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {

        if(r0 < 0 || r0 >= R || c0 < 0 || c0 >=C)
            return {};

        vector<vector<int>> vis = {static_cast<size_t>(R), vector<int>(C, 0)};
        vector<vector<int>> res = {};
        vis[r0][c0] = 1;
        res.push_back({r0, c0});
        int start = 0;
        while(res.size() - start > 0){
            int size = res.size();
            for(int i = start; i < size; i++){
                for(int d = 0; d < 4; d++){
                    int nx = res[i][0] + dxs[d];
                    int ny = res[i][1] + dys[d];
                    if(nx < 0 || nx >= R || ny < 0 || ny >= C || vis[nx][ny] == 1)
                        continue;
                    vis[nx][ny] = 1;
                    res.push_back({nx, ny});
                }
            }
            start = size;
        }
        return res;
    }
private:
    int dxs[4] = {0, 0, 1, -1};
    int dys[4] = {1, -1, 0, 0};
};