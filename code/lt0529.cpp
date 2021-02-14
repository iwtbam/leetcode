// https://leetcode-cn.com/problems/minesweeper/
// minesweeper
class Solution {
public:
    
    int dxs[8] = {0, 0, 1, -1,  1, -1, 1, -1};
    int dys[8] = {1, -1, 0, 0, -1,  1, 1, -1};
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {

        rows = board.size();
        if(rows == 0)
            return board;
        cols = board[0].size();
        this->board = board;
        int x = click[0], y = click[1];

        if(board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return board;
        }

        queue<pair<int, int>> q;
        deal(x, y);
        if(this->board[x][y] == 'B')
            q.emplace(x, y);

        while(q.size())
        {  
            auto [cx, cy] = q.front();
            q.pop();
            for(int i = 0; i < 8; i++)
            {
                int nx = cx + dxs[i];
                int ny = cy + dys[i];
                if(!valid(nx, ny) || this->board[nx][ny] != 'E')
                    continue;
                
                deal(nx, ny);
                if(this->board[nx][ny] == 'B')
                    q.emplace(nx, ny);
            }
        }

        return this->board;
    }

    bool valid(int x, int y)
    {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    void deal(int x, int y)
    {
        int num = 0;
        for(int i = 0; i < 8; i++)
        {
            int nx = x + dxs[i];
            int ny = y + dys[i];
            if(!valid(nx, ny))
                continue;
            if(this->board[nx][ny] == 'M' || this->board[nx][ny] == 'X')
                num++;
        }

        if(num > 0)
            this->board[x][y] = num + '0';
        else
            this->board[x][y] = 'B';

    }

private:
    vector<vector<char>> board;
    int rows, cols;

};