// https://leetcode-cn.com/problems/check-if-there-is-a-valid-path-in-a-grid/
// check if there is a valid path in a grid
class Solution {
public:


    int dirs[7][4]= {
        {0, 0, 0, 0},
        {0, -1, 0, 1}, //street 1
        {-1, 0, 1, 0}, //street 2
        {0, -1, 1, 0}, //street 3
        {1, 0, 0,  1}, //street 4
        {0, -1,-1, 0}, //street 5
        {-1, 0, 0, 1}  //street 6
    };

    bool hasValidPath(vector<vector<int>>& grid) {

        int m = grid.size();
        if(m == 0)
            return false;
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        queue<pair<int, int>> q;

        q.emplace(0, 0);

        vis[0][0] = 1;

        while(q.size())
        {
            auto [cx, cy] = q.front();

            //cout << cx << " " << cy << endl;

            if(cx == m - 1 && cy == n - 1)
                return true;

            q.pop();
            int cd = grid[cx][cy];

            for(int i = 0; i < 4; i += 2)
            {
                int nx = cx + dirs[cd][i];
                int ny = cy + dirs[cd][i + 1];

             //   cout <<"i:" << i << ", nx:" << nx << ", ny:" << ny << endl;

                if(nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny])
                    continue;

                int nd = grid[nx][ny];
                
                bool b1 = (dirs[cd][i] + dirs[nd][0] == 0) && (dirs[cd][i + 1] + dirs[nd][1] == 0);
                bool b2 = (dirs[cd][i] + dirs[nd][2] == 0) && (dirs[cd][i + 1] + dirs[nd][3] == 0);

                if(!(b1 || b2))
                    continue;
                vis[nx][ny]  = 1;
                q.emplace(nx, ny);

            }
        }       

        return false;
    }


private:
    vector<vector<int>> grid;
};