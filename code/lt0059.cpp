#include <vector>

using namespace std;

class Solution{

public:
    vector<vector<int>> generateMatrix(int n){
        if(n == 0)
            return {};
        
        vector<vector<int>> res = {n, vector<int>(n, 0)};
        int size = n * n, dir = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int x = 0, y = 0;

        res[x][y] = 1;

        for(int i = 1; i < size; i++)
        {
            int tx = x + dx[dir];
            int ty = y + dy[dir];

            if(tx >= n || tx < 0 || ty >=n || ty < 0 || res[tx][ty])
            {
                dir = (dir + 1) % 4;
                i = i -1;
            }
            else
            {
                x = tx;
                y = ty;
                res[x][y] = i;
            }
        }

        return res;
         
    }
};