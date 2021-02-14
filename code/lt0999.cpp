#include <vector>

using namespace std;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x = 0, y = 0;
        int rows = board.size();
        int cols = board[0].size();
        int find = 0;
        for(int i = 0; i < rows && !find; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'R'){
                    x = i;
                    y = j;
                    find = 1;
                    break;
                }
            }
        }
        
        int count = 0;
        
        for(int i = x; i < rows; i++){
            if(board[i][y] == '.')
                continue;
            if(board[i][y] == 'B' || board[i][y] == 'p'){
                count += board[i][y] == 'p';
                break;
            }
        }
        
        for(int i = x; i >= 0; i--){
            if(board[i][y] == '.')
                continue;
            if(board[i][y] == 'B' || board[i][y] == 'p'){
                count += board[i][y] == 'p';
                break;
            }
        }
        
        for(int i = y; i >= 0; i--){
            if(board[x][i] == '.')
                continue;
            if(board[x][i] == 'B' || board[x][i] == 'p'){
                count += board[x][i] == 'p';
                break;
            }
        }
        
        
        for(int i = y; i < cols; i++){
            if(board[x][i] == '.')
                continue;
            if(board[x][i] == 'B' || board[x][i] == 'p'){
                count += board[x][i] == 'p';
                break;
            }
        }
            
        return count;
    }
      
};