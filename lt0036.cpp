#include <vector>
#include <array>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9], cols[9][9], grids[9][9];
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(grids, 0, sizeof(grids));

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0;j < 9; j++)
            {
                if(board[i][j]!='.')
                {
                    int num = board[i][j] - '0' - 1;
                    if(rows[i][num]){
                        return false;
                    }
                    rows[i][num]++;
                    if(cols[j][num]){
                        return false;
                    }
                    cols[j][num]++;
                    int pos = i/3*3 + j/3;
                    if(grids[pos][num]){
                        return false;
                    }
                    grids[pos][num]++;
                }
            }
        }

        return true;
    }
};