#include <vector>

using namespace std;

class Solution{
public:

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    vector<int> sprialOrder(vector<vector<int>>& matrix){
        int row = matrix.size();
        if(row == 0)
            return {};

        int col = matrix[0].size();
        int size = row * col;    
        vector<int> res = {};    
        int dir = 0;
        int nx = 0, ny = 0;

        vector<vector<int>> visited = {row, vector<int>(col, 0)};
        visited[0][0] = 1;

        res.push_back(matrix[ny][nx]);

        for(int i = 1; i < size; i++)
        {
            int tx = nx + dx[dir];
            int ty = ny + dy[dir];

            if(tx < 0 || tx >= col || ty < 0 || ty >=row)
            {
                dir = (dir + 1) % 4;
                i = i -1;
                continue;
            }

            if(visited[tx][ty])
            {
                dir = (dir + 1) % 4;
                i = i -1;
                continue;
            }

            nx = tx;
            ny = ty;
            visited[ny][nx] = 1;
            res.push_back(matrix[ny][nx]);

        }
        return res;
    }
};