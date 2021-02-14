// https://leetcode-cn.com/problems/game-of-life/
// game of life
class Solution {
public:
    int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
    
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty())
            return;
        
        vector<vector<int>> record = board;
        int rows = board.size();
        int cols = board[0].size();
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int count = 0;
                for(int d = 0; d < 8; d++){
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(nx >=0 && ny >= 0 && nx < rows && ny < cols && record[nx][ny])
                        count++;
                        
                }
                
                if(count < 2)
                    board[i][j] = 0;
                else if(count <= 3){
                    if(count==3 &&  board[i][j]==0)
                        board[i][j] = 1;
                }else
                    board[i][j] = 0;
                    
            }
        }
        
    }
    
};