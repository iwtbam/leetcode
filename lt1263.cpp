// https://leetcode-cn.com/problems/minimum-moves-to-move-a-box-to-their-target-location/
// minimum moves to move a box to their target location
struct State 
{
    int x, y, dir;
    State(int x = 0, int y = 0, int dir = 0):x(x), y(y), dir(dir){};
};

class Solution {
public:
    //           ср, об,вС, ио
    int dxs[4] = {0, -1, 0, 1};
    int dys[4] = {-1, 0, 1, 0};

    int minPushBox(vector<vector<char>>& grid) {
        this->grid = grid;
        rows = this->grid.size();
        if(rows == 0)
            return 0;
        cols = this->grid[0].size();
        
        parse();

        queue<State> q;
        q.emplace(bx, by, -1);

        box.resize(rows, vector<vector<int>>(cols, vector<int>(4, -1)));
        while(q.size())
        {
            auto [cx, cy , cd] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++){
                int nx = cx + dxs[k];
                int ny = cy + dys[k];

                if(!check_bound(nx, ny) || grid[nx][ny] == '#' || box[nx][ny][(k + 2) % 4] != -1 || !expand(cx, cy, cd, (k + 2) % 4))
                    continue;
                box[nx][ny][(k + 2) % 4] = (cd >= 0 ? box[cx][cy][cd] : 0) + 1;
                q.emplace(nx, ny, (k + 2) % 4);
                if(nx == tx && ny == ty)
                    return box[nx][ny][(k + 2) % 4];
            }    
        }

        return -1;
    }

    bool expand(int x, int y, int cd, int nd){

        int cx = cd >= 0 ? x + dxs[cd] : hx;
        int cy = cd >= 0 ? y + dys[cd] : hy;
        int dx = x + dxs[nd];
        int dy = y + dys[nd];

        if(cx == dx && cy ==  dy)
            return 1;
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        vis[x][y] = 1;
        vis[cx][cy] = 1;
        queue<pair<int, int>> q;
        q.emplace(cx, cy);
        while(q.size())
        {            
            auto [cx, cy] = q.front();
            q.pop();
            for(int d = 0;  d < 4; d++){
                int nx = cx + dxs[d];
                int ny = cy + dys[d];
                if(!check_bound(nx, ny)|| grid[nx][ny] == '#' || vis[nx][ny])
                    continue;
                vis[nx][ny] = 1;
                if(nx == dx && ny == dy)
                    return true;
                q.emplace(nx, ny);
            }   
        } 
        return false;
    }


    bool check_bound(int x, int y){
        return x >= 0 && x < rows &&  y >= 0 && y < cols;
    }

    void parse()
    {
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 'S'){
                    hx = i;
                    hy = j;
                }
                if(grid[i][j] == 'B'){
                    bx = i;
                    by = j;
                }
                if(grid[i][j] == 'T'){
                    tx = i;
                    ty = j;
                }
            }
        }
    }

private:
    int bx, by, hx, hy, tx, ty;
    int rows, cols;
    vector<vector<char>> grid;
    vector<vector<vector<int>>> man;
    vector<vector<vector<int>>> box;
    
};