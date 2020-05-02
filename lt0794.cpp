#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int x = {0}, o = {0};
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == 'X')
                    x++;
                if(board[i][j] == 'O')
                    o++;
            }
        }
        if(!(x - o == 1 || x - o == 0))
            return false;

        int xn = check(board, 'X') ;
        int on = check(board, 'O');
        
        if(xn + on == 0)
            return true;
        
        if(xn == 1 && on == 0 && x == o + 1)
            return true;
        
        if(xn == 0 && on == 1 && x == o)
            return true;

        if(xn == 2 && on == 0 && x + o == 9)
            return true;
    
        return false;
    }

    int check(vector<string>& board, char c){
        int num = 0;
        num = num + (c == board[0][0] && c == board[0][1] && c == board[0][2]);
        num = num + (c == board[1][0] && c == board[1][1] && c == board[1][2]);
        num = num + (c == board[2][0] && c == board[2][1] && c == board[2][2]);

        num = num + (c == board[0][0] && c == board[1][0] && c == board[2][0]);
        num = num + (c == board[0][1] && c == board[1][1] && c == board[2][1]);
        num = num + (c == board[0][2] && c == board[1][2] && c == board[2][2]);

        num = num + (c == board[0][0] && c == board[1][1] && c == board[2][2]);
        num = num + (c == board[2][0] && c == board[1][1] && c == board[0][2]);
        
        // cout << num << endl;
        return num;
    }
};