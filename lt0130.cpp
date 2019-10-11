#include <vector>
#include <queue>
using namespace std;



class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if(rows == 0)
            return;
        int cols = board[0].size();
        vector<vector<int>> visited = {rows, vector<int>(cols, 0)};
        
        
        for(int i = 0; i < rows; i++)
        {
            if(board[i][0]=='O' && !visited[i][0])
                 helper(board, visited, i, 0, 'O');
            if(board[i][cols-1]=='O' && !visited[i][cols-1])
                 helper(board, visited, i, cols - 1, 'O');
        }
        
        
        
        for(int j = 0; j < cols; j++)
        {
            if(board[0][j]=='O' && !visited[0][j])
                 helper(board, visited, 0, j, 'O');
            if(board[rows-1][j]=='O' && !visited[rows-1][j])
                 helper(board, visited, rows-1, j, 'O');
                
        }
        
        for(int i = 1; i < rows - 1; i++)
        {
            for(int j = 1; j < cols - 1; j++)
            {
                if(!visited[i][j])
                {
                    board[i][j] = 'X';    
                }
            }
        }
    }

    void helper(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, char tag){
        int rows = board.size();
        int cols = board[0].size();
        queue<pair<int, int>> q;
        visited[i][j] = 1;
        board[i][j] = tag;
        q.push({i, j});
        while(q.size())
        {
            auto [cx, cy] = q.front();
            
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if(nx >=0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny] && board[nx][ny]=='O')
                {
                    q.push({nx, ny});
                    visited[nx][ny] = 1;
                    board[nx][ny] = tag;
                }
            }
        }
    }
};