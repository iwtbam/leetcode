// https://leetcode-cn.com/problems/cat-and-mouse-ii/
// cat and mouse ii
class Solution {
public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        memset(dp, -1, sizeof(dp));

        int cx, cy, mx, my;
        rows = grid.size();
        cols = grid[0].size();
        cj = catJump;
        mj = mouseJump;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 'C'){
                    cx = i;
                    cy = j;
                }else if(grid[i][j] == 'M'){
                    mx = i;
                    my = j;
                }
            }
        }

        return canMouseWin(grid, cx, cy, mx, my, 0, 0);
    }

    int canMouseWin(const vector<string>& grid, int cx, int cy, int mx, int my, int step, int turn){
        
       // cout << step << " " << turn << endl;

        if(step > 67)
            return 0;


        if(grid[cx][cy] == 'F')
            return 0;

        if(cx == mx && cy == my)
            return 0;
        
        if(grid[mx][my] == 'F')
            return 1;

        if(dp[cx][cy][mx][my][step] != -1)
            return dp[cx][cy][mx][my][step];

        if(turn == 0){
            for(int d = 0; d < 4; d++){
                for(int jump = 0; jump <= mj; jump++){
                    int nx = mx + dxs[d] * jump;
                    int ny = my + dys[d] * jump;
                    if(nx < 0 || nx >= rows || ny < 0 || ny >= cols || grid[nx][ny] == '#')
                        break;
                    
                    if(canMouseWin(grid, cx, cy, nx, ny, step + 1, turn ^ 1))
                        return dp[cx][cy][mx][my][step] = 1;
                }
            }
            return dp[cx][cy][mx][my][step] = 0;
        }else{
            for(int d = 0; d < 4; d++){
                for(int jump = 0; jump <= cj; jump++){
                    int nx = cx + dxs[d] * jump;
                    int ny = cy + dys[d] * jump;
                    if(nx < 0 || nx >= rows || ny < 0 || ny >= cols || grid[nx][ny] == '#')
                        break;
                    
                    if(!canMouseWin(grid, nx, ny, mx, my, step + 1, turn ^ 1))
                        return dp[cx][cy][mx][my][step] = 0;
                }
            }
            return dp[cx][cy][mx][my][step] = 1;
        }
    }

private:
    int dp[10][10][10][10][100] = {0};
    int rows, cols, cj, mj;
    int dxs[4] = {0, 0, 1, -1};
    int dys[4] = {1, -1, 0, 0};
};