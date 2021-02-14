// https://leetcode-cn.com/problems/shortest-bridge/
// shortest bridge
class Solution {
public:

    int dxs[4] = {0, 0, 1, -1};
    int dys[4] = {1, -1, 0, 0};

    int shortestBridge(vector<vector<int>>& A) {
        int rows = A.size();
        if(rows == 0)
            return 0;
        int cols = A[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        queue<pair<int, int>> q;
        queue<pair<int, int>> eq;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(A[i][j]){
                    q.emplace(i, j);
                    vis[i][j] = 1;
                    break;
                }
            }
            if(q.size())
                break;
        }

        while(q.size()){
            auto [cx, cy] = q.front();
            q.pop();
            bool isE = false;
            for(int i = 0; i < 4; i++){
                int nx = cx + dxs[i];
                int ny = cy + dys[i];
                if(nx < 0 || nx >= rows || ny < 0 || ny >= cols || vis[nx][ny])
                    continue;
                
                if(A[nx][ny] == 0){
                    isE = true;
                    continue;
                }

                vis[nx][ny] = 1;
                q.emplace(nx, ny);
            }

            if(isE)
                eq.emplace(cx, cy);     
        }

        int dis = 0;
        while(eq.size()){
            size_t size = eq.size();
            // for(int i = 0; i < rows; i++){
            //     for(int j = 0; j < cols; j++)
            //         cout << vis[i][j] << " ";
            //     cout << endl;
            // }
            // cout << "------" << endl;
            for(int i = 0; i < size; i++){
                auto [cx, cy] = eq.front();
                eq.pop();            
                for(int d = 0; d < 4; d++){
                    int nx = cx + dxs[d];
                    int ny = cy + dys[d];
                    if(nx < 0 || nx >= rows || ny < 0 || ny >= cols || vis[nx][ny])
                        continue;
                    if(A[nx][ny] == 1)
                        return dis;
                    vis[nx][ny] = 1;
                    eq.emplace(nx, ny);
                }
            }
            dis++;
        }
        return 1;
    }
};