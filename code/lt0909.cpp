// https://leetcode-cn.com/problems/snakes-and-ladders/
// snakes and ladders
class Solution {
public:

    int snakesAndLadders(vector<vector<int>>& board) {
        rows = board.size();
        if(rows == 0)
            return 0;
        cols = board[0].size();
        vector<int> dis(rows * cols + 1, INT_MAX);
        queue<int> q;
        q.push(1);
        dis[1] = 0;
        int target = rows * cols;
        while(q.size())
        {
            int x = q.front();
            if(x == target)
                return dis[x]; 
            q.pop();
            for(int i = 1; i <= 6 && x + i <= target; i++)
            {
                auto [nr, nc] = calc(x + i);
                int nx = board[nr][nc] == -1 ? x + i : board[nr][nc];
                if(dis[x] + 1 < dis[nx]){
                    dis[nx] = dis[x] + 1;
                    q.emplace(nx);
                }
            }
                
        }
        return -1;
    }

    pair<int, int> calc(int pos)
    {
        int row = (pos - 1) / cols;
        int col = (pos - 1) % cols;

        return {rows - row - 1, row % 2 == 1 ? cols - col - 1 : col};
    } 

private:
    int rows, cols;
};